/*
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

// Sensor pin
int sensorPin = A0; // koppla sensorn hit

// Variabler för sensor och siffra
int sensorValue = 0;
int displayNumber = 0;

// Segmentmönster för siffrorna 0-9 (gemensam katod)
// 1 = LED på, 0 = LED av
int numbers[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  Serial.begin(9600); // starta seriell monitor

  // Ställ in 7-segment pins som OUTPUT
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // Läs sensorvärde (0-1023)
  sensorValue = analogRead(sensorPin);

  // Konvertera sensorvärde till 0-9
  displayNumber = map(sensorValue, 0, 1023, 0, 9);

  // Skriv ut på seriell monitor
  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" → Display: ");
  Serial.println(displayNumber);

  // Visa siffran på 7-segment
  digitalWrite(a, numbers[displayNumber][0]);
  digitalWrite(b, numbers[displayNumber][1]);
  digitalWrite(c, numbers[displayNumber][2]);
  digitalWrite(d, numbers[displayNumber][3]);
  digitalWrite(e, numbers[displayNumber][4]);
  digitalWrite(f, numbers[displayNumber][5]);
  digitalWrite(g, numbers[displayNumber][6]);

  delay(200); // liten paus
}
*/