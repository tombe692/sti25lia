#include "secretinfo.h"//YOUR SECRET FILE!
#include <WiFi.h>

#define BLYNK_TEMPLATE_ID YOUR_TEMPLATE_ID
#define BLYNK_TEMPLATE_NAME YOUR_TEMPLATE_NAME  
#define BLYNK_AUTH_TOKEN YOUR_AUTH_TOKEN

#include <BlynkSimpleWifi.h>
#include "temp.h"


const char* ssid = YOUR_SSID;
const char* pass = YOUR_PASS;

void setup()
{
  Serial.begin(115200);
  Serial.println("--- STARTING ---");
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  setupSensor(); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Setup completed");
}


void loop()
{
  Blynk.run();
  
  float temp = lasTemperatur();
  float humidity = lasFuktighet(); 

  printTempInfo();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("ERROR: Failed to read from DHT sensor!");
  } else {
    Serial.println("Sensor reading OK - sending to Blynk");
  }
  
  Blynk.virtualWrite(V3, temp);
  Blynk.virtualWrite(V4, humidity);
  
  delay(20000);
}