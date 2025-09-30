/*
    const int pin_latch = 8; 
    const int pin_clock = 12;	
    const int pin_data = 11; 	

    int num_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    void setup(){
        pinMode(pin_latch, OUTPUT);
        pinMode(pin_clock, OUTPUT);
        pinMode(pin_data, OUTPUT);
    }

    void loop(){
        for (int i=0; i<10; i++) {
            digitalWrite(pin_latch, LOW);
            shiftOut(pin_data, pin_clock, MSBFIRST, num_arr[i]);
            digitalWrite(pin_latch, HIGH);
            delay(1000);
        }
    }
*/