/*

int Pin1 = 2;
int Pin2 = 3;

bool led1 = false;
bool led2 = false;

void setup() {
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Type 1/2 ");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "1") {
      led1 = !led1;
      digitalWrite(Pin1, led1 ? HIGH : LOW);
    } 
    else if (command == "2") {
      led2 = !led2;
      digitalWrite(Pin2, led2 ? HIGH : LOW);
      
    }
  }
}


*/