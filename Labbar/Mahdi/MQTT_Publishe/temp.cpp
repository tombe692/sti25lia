// tempratur.cpp
#include "temp.h"
#include <Arduino.h>

// Definitioner
const int sensorPin = 7;
float temperatur = 0;
float fuktighet = 0;
bool sensorStatus = false;
DHT dht(sensorPin, DHT22);

void setupSensor() {
  dht.begin(); 
  delay(2000);
}

float lasTemperatur() {
  temperatur = dht.readTemperature(); 
  return temperatur;
}

float lasFuktighet() {
  fuktighet = dht.readHumidity();
  return fuktighet; 
}

void printTempInfo(){
  Serial.print("Temperatur: ");
  Serial.print(temperatur);
  Serial.println("°C");
  Serial.print("Fuktighet: ");
  Serial.print(fuktighet);
  Serial.println("%");
  Serial.println("------------");
}
