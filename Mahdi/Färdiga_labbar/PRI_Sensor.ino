#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int LED = 2;
int PIRsensor = 3;
int PIRstate = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIRsensor, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Wating to PIR...");
  delay(500);
}

void loop() {
  PIRstate = digitalRead(PIRsensor);

  if (PIRstate == HIGH) {
    // Rörelse upptäckt
    digitalWrite(LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Moving");
    delay(100);
  } else {
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("no moving");
  }

  delay(500);
}
