#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Pinnar
const int ledPin = 8;      // LED kopplad till pin 8
const int buttonPin = 2;   // Knapp kopplad till pin 2

// Variabler
int buttonState = 0;       // Lagrar knappens status
int buttonLastState=0;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(ledPin, OUTPUT);     // Ställ in LED som utgång
  pinMode(buttonPin, INPUT);   // Ställ in knappen som ingång
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LCD STARTAR");
  delay(1000);
  
}

void loop() {
  // Läs av knappens status (HIGH om tryckt, LOW om ej tryckt)
  buttonState = digitalRead(buttonPin);
  
if(buttonLastState!=buttonState){
    if (buttonState == HIGH) {
      digitalWrite(ledPin, HIGH);   // Tänd LED
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Light is ON");
    } else {
      digitalWrite(ledPin, LOW);    // Släck LED
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Light is OFF");
    }
    delay(500);
  }
  buttonLastState=buttonState;
}

