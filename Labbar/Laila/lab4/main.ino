/*
int sensorPin = A0;   // Här anger vi vilken pin sensorn sitter på (A0 = analog pin 0)
int sensorValue = 0;  // Här sparar vi det värde vi läser från sensorn

void setup() {
  // setup() körs bara en gång när du startar din Arduino
  Serial.begin(9600);  // Starta seriell kommunikation med datorn, hastighet 9600 bps
}

void loop() {
  // loop() körs om och om igen hela tiden
  sensorValue = analogRead(sensorPin);  // Läs värdet från sensorn och spara i sensorValue
  Serial.println(sensorValue);          // Skicka värdet till seriell monitor så vi kan se det
  delay(500);                           // Vänta 0,5 sekunder innan nästa läsning
} 
  */