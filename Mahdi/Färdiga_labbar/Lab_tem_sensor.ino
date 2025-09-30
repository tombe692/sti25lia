#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
int TempPin=A0;
int tempValue;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("LCD STARTAR");
  delay(2000);
}

void loop() {
  tempValue=analogRead(TempPin);
  float voltag=tempValue*(5.0 / 1023.0);
  float tempraturC=(voltag-0.5)*100;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp: ");
  lcd.print(tempraturC);
  lcd.print(" C");
  delay(2000);
}
