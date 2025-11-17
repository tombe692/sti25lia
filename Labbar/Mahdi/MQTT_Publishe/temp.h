#ifndef TEMP_H  // Include guard
#define TEMP_H

#include <DHT.h>

// Deklarationer
extern const int sensorPin;
extern float temperatur;
extern float fuktighet;
extern bool sensorStatus;
extern DHT dht;

// Funktionsdeklarationer
void setupSensor();
float lasTemperatur();
float lasFuktighet();
void printTempInfo();

#endif