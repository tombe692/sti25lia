/*
#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;   // LM35 på A0
int sensorValue = 0;  // råvärde från sensorn
float temperature = 0;

void setup() {
  Serial.begin(9600);   // starta seriell monitor
  lcd.begin(16, 2);     // starta LCD (16x2)
  lcd.print("Temp Sensor...");
}

void loop() {
  // Läs värde från LM35
  sensorValue = analogRead(sensorPin);

  // Omvandla till grader Celsius
  // LM35: 10 mV per grad, Arduino: 5V/1024 ≈ 4.88 mV per steg
  temperature = (sensorValue * 5.0 * 100.0) / 1024.0;

  // Skriv till seriella monitorn
  Serial.print("Temperatur: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Skriv till LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  delay(1000); // vänta 1 sekund
} */