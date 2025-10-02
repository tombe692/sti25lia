/*


#include <Adafruit_LiquidCrystal.h>

const int tempPin = A0;

Adafruit_LiquidCrystal lcd_1(0);

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp:");
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  lcd_1.setCursor(0, 1);
  lcd_1.print("        ");
  lcd_1.setCursor(0, 1);
  lcd_1.print(temperatureC, 1);
  lcd_1.print(" C");

  delay(1000);
}







*/