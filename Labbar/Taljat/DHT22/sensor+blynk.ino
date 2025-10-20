#define BLYNK_TEMPLATE_ID "TMPL4oNZiSyQF"
#define BLYNK_TEMPLATE_NAME "DHT22"
#define BLYNK_TEMPLATE_TOKEN "Y1jB4WvSoIf92v44YFYMGSOP4SKQDKWc"



#define BLYNK_PRINT Serial
#include "BlynkSimpleWifi.h"
#include "WiFiS3.h"
 
#include "DHT.h"
#define DHTPIN 2          
#define DHTTYPE DHT22     
DHT dht(DHTPIN, DHTTYPE);


char auth[] = BLYNK_TEMPLATE_TOKEN;
char ssid[] = "STI Student";  //  Wifi Username
char pass[] = "STI1924stu";  //  Wifi password



void setup() {
  Serial.begin(9600);
  dht.begin();           // DHT sensor
  Blynk.begin(auth, ssid, pass); // Wi-Fi & Blynk Cloud
}

void loop() {
  Blynk.run();           

  float temp = dht.readTemperature(); 
  float hum  = dht.readHumidity();    

  
  if (!isnan(temp)) {
    Blynk.virtualWrite(V1, temp); 
    Serial.print("Temperature: "); Serial.print(temp); Serial.println(" °C");
  } else {
    Serial.println("Failed to read temperature!");
  }

  if (!isnan(hum)) {
    Blynk.virtualWrite(V2, hum);   
    Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %");
  } else {
    Serial.println("Failed to read humidity!");
  }

  delay(2000); 
}

