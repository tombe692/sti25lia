// To use Wifi
#include "WiFiS3.h"
#include "ThingSpeak.h"
#include "arduino_secrets.h"//your wifi info...
#include "tempratur.h"
#include "RTC.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
//---------------vonvertTime------
#include <TimeLib.h> 
//--------------RTC----------
WiFiUDP Udp;
NTPClient timeClient(Udp);

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = _SSID;          // your network SSID (name)
char pass[] = _PASS;          // your network password
int status = WL_IDLE_STATUS;  // the WiFi radio's status
WiFiClient client;
 
unsigned long myChannelNumber = _CH_ID;
const char * myWriteAPIKey = _WRITE_APIKEY;
const char * myReadAPIKey = _Read_APIKEY;


//----------------------------struct for save time------------------
typedef struct{
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
  } DateTimeParts;


 //----------------------------------------------------------
  int number = 0;
  unsigned long previousMillis = 0;
  const long interval = 20000;  // interval at which to update (milliseconds)
///------------------------setRTC------------------------------
void setRTC(){
    RTC.begin();
    Serial.println("\nStarting connection to server...");
    timeClient.begin();
    timeClient.update();
  }
//-------------------uppdateRTC-------------------------------
void uppdateRTC(){
  timeClient.update();//-------------------------
  auto timeZoneOffsetHours = 2;
  auto unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours *3600);
  RTCTime timeToSet = RTCTime(unixTime);
  RTC.setTime(timeToSet);
  // Retrieve the date and time from the RTC and print them
  // RTCTime currentTime;
  // RTC.getTime(currentTime); 
  //Serial.println("The RTC was just set to: " + String(currentTime));
  // Serial.print("The RTC was just set to: ");
  // Serial.println(currentTime);
  }

//--------------------GetRTC data--------------------------------
DateTimeParts getRTCData(){
    RTCTime currentTime;
    RTC.getTime(currentTime); 
    DateTimeParts RTCparts;
    RTCparts.year    = currentTime.getYear();
    RTCparts.month   = (int)currentTime.getMonth()+1;
    RTCparts.day     = currentTime.getDayOfMonth();
    RTCparts.hours   = currentTime.getHour();
    RTCparts.minutes = currentTime.getMinutes();
    RTCparts.seconds = currentTime.getSeconds();
    Serial.print("RTC Time: ");
    Serial.print(RTCparts.year);
    Serial.print("-");
    Serial.print(RTCparts.month);
    Serial.print("-");
    Serial.print(RTCparts.day);
    Serial.print(" ");
    Serial.print(RTCparts.hours);
    Serial.print(":");
    Serial.print(RTCparts.minutes);
    Serial.print(":");
    Serial.println(RTCparts.seconds);
    return RTCparts;
}

time_t  getRTCunixTime(){
   DateTimeParts RTCparts = getRTCData();
  //----------------convertera time to second---------
  tmElements_t tm;
    tm.Year = RTCparts.year - 1970;
    tm.Month = RTCparts.month;
    tm.Day = RTCparts.day;
    tm.Hour = RTCparts.hours;
    tm.Minute = RTCparts.minutes;
    tm.Second = RTCparts.seconds;
    
    time_t RTCunixTime = makeTime(tm);
    Serial.print("Unix RTC Time: ");
    Serial.println(RTCunixTime);
    return RTCunixTime;
}

//----------------------------get data from thingspeack---------------
DateTimeParts parseTimestamp(const String& timestamp) {
    DateTimeParts dtp;
    dtp.year = timestamp.substring(0, 4).toInt();     // 0-3 = year "2024" 
    dtp.month = timestamp.substring(5, 7).toInt();    // 5-6 = month "01"
    dtp.day = timestamp.substring(8, 10).toInt();     // 8-9 = day "15"
    dtp.hours = timestamp.substring(11, 13).toInt();  // 11-12 hours = "14"
    dtp.minutes = timestamp.substring(14, 16).toInt(); // 14-15 minutes = "40"
    dtp.seconds = timestamp.substring(17, 19).toInt(); // 17-18 secounds = "10"

    return dtp;
}

time_t getThingunixTime(const String& timestamp){ 
  DateTimeParts dtp = parseTimestamp(timestamp);
    //----------------convertera time to second---------
    tmElements_t tm;
    tm.Year = dtp.year - 1970;
    tm.Month = dtp.month;
    tm.Day = dtp.day;
    tm.Hour = dtp.hours;
    tm.Minute = dtp.minutes;
    tm.Second = dtp.seconds;

    time_t ThingunixTime = makeTime(tm);
    auto timeZoneOffsetHours = 2;
    ThingunixTime += (timeZoneOffsetHours * 3600);
    Serial.print("Unix Thingspeak Time: ");
    Serial.println(ThingunixTime);
    return ThingunixTime; 
}

void readThingSpeackData(){
    int read = ThingSpeak.readMultipleFields(myChannelNumber, myReadAPIKey);
    if(read==200){
    float temperatur = ThingSpeak.getFieldAsFloat(1);
    float fuktighet = ThingSpeak.getFieldAsFloat(2);
    Serial.print("Temp: ");
    Serial.print(temperatur);
    Serial.print("°C, Fukt: ");
    Serial.print(fuktighet);
    Serial.println("%");
  }else{
    Serial.print("kunde inte lasa data.... ");
    delay(20000); 
  }
}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  //Starta temperatur sensorn!
  setupSensor();
  Serial.println("Arduino ThingSpeak Client Starting...");
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true); // don't continue
  }
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
  // Connect to WiFi
  connectToWiFi();
  // Initialize ThingSpeak
  ThingSpeak.begin(client);
  Serial.println("Setup complete!");
  Serial.println("Ready to send data to ThingSpeak...");
}

void connectToWiFi() {
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  int attempts = 0;
  while (status != WL_CONNECTED && attempts < 10) {
    status = WiFi.begin(ssid, pass);
    Serial.print("Attempt ");
    Serial.print(attempts + 1);
    Serial.println("...");
    delay(5000);
    attempts++;
  }
  if (status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection after 10 attempts");
    Serial.println("Please check your credentials and try again");
    while(true);
  } 
  else {
    Serial.println("Connected to WiFi successfully!");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Signal Strength (RSSI): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
  }
  //--------setRTC------
  setRTC();
  getRTCData();
}

void loop() 
{
  unsigned long currentMillis = millis(); 
  // Check WiFi connection periodically
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi disconnected - attempting to reconnect...");
    connectToWiFi();
    return;
  }
  // ---------Get RTC data and print it-------
  DateTimeParts rtcData = getRTCData();

  // ---------thingspeack date-------
  String createdAt = ThingSpeak.readCreatedAt (myChannelNumber, myReadAPIKey);
  DateTimeParts parts = parseTimestamp(createdAt);
  int dateArray[6] = {
    parts.year,
    parts.month,
    parts.day,
    parts.hours,
    parts.minutes,
    parts.seconds
  };
  Serial.print("year is: ");
  Serial.println(dateArray[0]);
  //-----------------------------------
  getRTCunixTime();
  getThingunixTime(createdAt);
  int timeDif = abs(getRTCunixTime() - getThingunixTime(createdAt));
  // int timeDif=getRTCunixTime() - getThingunixTime(createdAt);
  Serial.print("Time dif is: ");
  Serial.println(timeDif);
  //-----------------------------------

  //------------------------read data from Thingspeak-----------------
  //readThingSpeackData()

  // Update ThingSpeak every interval
  // if (currentMillis - previousMillis >= interval)
  // {
  //   previousMillis = currentMillis;
  if(timeDif>=15){
    float temperatur = lasTemperatur();
    float fuktighet = lasFuktighet();
    ThingSpeak.setField(1, temperatur);
    ThingSpeak.setField(2, fuktighet);


    int httpCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    if(httpCode == 200)
    {
      Serial.println("Channel update successful");
      delay(22000);
    }
    else
    {
      Serial.println("Problem updating channel. HTTP error code: " + String(httpCode));
      delay(45000);
    }
    Serial.println("Next update in 20 seconds...");
    Serial.println("--------------------");
  }

  static unsigned long lastSensorRead = 0;
  if (currentMillis - lastSensorRead >= 20000)
  {
    lastSensorRead = currentMillis;
    lasTemperatur();
    lasFuktighet();
      // ---------Uppdate RTC-------
    uppdateRTC();
  }
  delay(1000);
}
