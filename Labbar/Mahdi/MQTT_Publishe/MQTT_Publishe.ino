#include "arduino_secrets.h"
#include <ArduinoMqttClient.h>
#include <WiFiS3.h>
#include "temp.h"

const char* ssid = SECRET_SSID;
const char* pass = SECRET_PASS;

// const char * ClientUser = "yourmqttuser";
// const char * ClientPass = yourmqttpass;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

//online test broker  "test.mosquitto.org"
const char broker[] = "test.mosquitto.org";
int port = 1883;

// const char* broker = "Your_SECRET_BROKER";
// const int port = "Your_SECRET_BROKER_PORT";

const char MyTempTopic[] = "your topic";

const long interval = 10000;
unsigned long previousMillis = 0;

void setup() {
  setupSensor();
  Serial.begin(9600);
  while(!Serial){};

  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);

  while(WiFi.begin(ssid, pass) != WL_CONNECTED){
    Serial.print(".");
    delay(5000);
  }

  Serial.print("You're connected to the network");
  Serial.println();

  //MQTT password
  // mqttClient.setUsernamePassword(ClientUser, ClientPass);
  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if(!mqttClient.connect(broker, port)){
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());
    while(1);
  }

  Serial.println("Connected to MQTT broker!");
}

void loop() {
  mqttClient.poll();
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    mqttClient.beginMessage(MyTempTopic);
    mqttClient.print(lasTemperatur());
    mqttClient.endMessage();

    Serial.print("Temperature sent: ");
    Serial.println(lasTemperatur()); 
  }
}

