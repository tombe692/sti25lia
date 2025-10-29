/*
#include <WiFiS3.h>  // finns redan inbyggt i Uno R4 WiFi, ingen extra lib behövs
#include <BlynkSimpleWiFi.h>


#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT); // Säg att pin 13 ska vara en LED
}

void loop() {
  digitalWrite(13, HIGH); // Tänd LED
  delay(1000);            // Vänta 1 sekund
  digitalWrite(13, LOW);  // Släck LED
  delay(1000);            // Vänta 1 sekund
}
*/


#define BLYNK_TEMPLATE_ID "TMPL4Fny2vhRT"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "lCHxNSyigpLDRR8IvFHfFkKI0tUi7dfW"

#define BLYNK_PRINT Serial

#include <WiFiS3.h>            // För Arduino UNO R4 WiFi
#include <BlynkSimpleWiFi.h>   // Blynk-biblioteket

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Tele2_375283";   // Ditt Wi-Fi-namn
char pass[] = "x2xymajz";       // Ditt Wi-Fi-lösenord

int ledPin = 13; // LED sitter på pin 13

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run(); // håller kopplingen igång
}

// När du trycker på knappen i appen
BLYNK_WRITE(V0) {
  int ledState = param.asInt();  // Läs värdet (0 eller 1)
  digitalWrite(ledPin, ledState); // Tänd eller släck LED
}
 