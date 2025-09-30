/*

#include <Adafruit_NeoPixel.h>

int pin = 12;
int NumPixel = 3;


Adafruit_NeoPixel pixels(NumPixel, pin, NEO_GRB + NEO_KHZ800);

void setup(){
  
	pixels.begin();

}


void loop(){
  
  // Turn on each pixel 
  
  //Red
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(2000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); //off
  
  //Yellow1
  pixels.setPixelColor(1, pixels.Color(255, 150, 0)); 
  pixels.show();
  delay(2000);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); //off
  
  //Green
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));   
  pixels.show();
  delay(5000);
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));

  //Yellow2
  pixels.setPixelColor(1, pixels.Color(255, 150, 0)); 
  pixels.show();
  delay(2000);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); //off
  
 

}


*/