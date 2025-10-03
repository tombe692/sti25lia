/*
// Definiera sensorer
int pirPin = 2;   // PIR sensor ansluten till pin 2
int irPin = 3;    // IR sensor ansluten till pin 3

// Definiera LED:ar
int ledPir = 8;   // LED för PIR
int ledIr = 9;    // LED för IR

void setup() {
  // Ställ in sensorer som input
  pinMode(pirPin, INPUT);
  pinMode(irPin, INPUT);

  // Ställ in LED:ar som output
  pinMode(ledPir, OUTPUT);
  pinMode(ledIr, OUTPUT);

  // Starta seriell monitor
  Serial.begin(9600);
  Serial.println("System startat!");
}

void loop() {
  // Läs sensorstatus
  int pirState = digitalRead(pirPin);
  int irState = digitalRead(irPin);

  // PIR-sensor styr LED och skriv ut i Serial Monitor
  if (pirState == HIGH) {
    digitalWrite(ledPir, HIGH);       // Tänd PIR LED
    Serial.println("Rörelse upptäckt!");
  } else {
    digitalWrite(ledPir, LOW);        // Släck PIR LED
  }

  // IR-sensor styr LED och skriv ut i Serial Monitor
  if (irState == HIGH) {
    digitalWrite(ledIr, HIGH);        // Tänd IR LED
    Serial.println("IR-sensor aktiverad!");
  } else {
    digitalWrite(ledIr, LOW);         // Släck IR LED
  }

  delay(200); // liten paus för stabil serial output
}
*/ 