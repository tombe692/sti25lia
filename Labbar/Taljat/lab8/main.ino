/*

const int Pin = 2;

void setup() {
  pinMode(Pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Type ON/OFF");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.equalsIgnoreCase("ON")) {
      digitalWrite(Pin, HIGH);
      Serial.println("LED is ON");
    } 
    else if (command.equalsIgnoreCase("OFF")) {
      digitalWrite(Pin, LOW);
      Serial.println("LED is OFF");
    } 
  }   
}




*/