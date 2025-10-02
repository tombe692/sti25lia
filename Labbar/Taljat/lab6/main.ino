/* 

#include <Adafruit_LiquidCrystal.h>


const int trigPin = 10;  
const int echoPin = 9;

float duration, distance;

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Distance:");
  
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);
  distance = (duration* 0.0343)/2;
  
   // Display on LCD
  lcd_1.setCursor(0, 1); // second row
  lcd_1.print("      ");  // clear previous value
  lcd_1.setCursor(0, 1);
  lcd_1.print(distance, 1);
  lcd_1.print(" cm");

  delay(200); // small delay
 
}




*/