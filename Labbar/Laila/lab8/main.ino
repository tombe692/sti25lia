/*
int led1 = 8;  // LED1 på pin 8
int led2 = 9;  // LED2 på pin 9
String command; // för att läsa seriell input

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600); // starta seriell monitor
  Serial.println("Skriv '1' för LED1 ON, '0' för LED1 OFF");
  Serial.println("Skriv '2' för LED2 ON, '3' för LED2 OFF");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readString(); // läs vad användaren skriver

    command.trim(); // ta bort extra mellanslag eller radbryt

    if (command == "1") {
      digitalWrite(led1, HIGH);
      Serial.println("LED1 ON");
    } 
    else if (command == "0") {
      digitalWrite(led1, LOW);
      Serial.println("LED1 OFF");
    } 
    else if (command == "2") {
      digitalWrite(led2, HIGH);
      Serial.println("LED2 ON");
    } 
    else if (command == "3") {
      digitalWrite(led2, LOW);
      Serial.println("LED2 OFF");
    } 
    else {
      Serial.println("Fel kommando! Skriv 0,1,2 eller 3.");
    }
  }
}
*/