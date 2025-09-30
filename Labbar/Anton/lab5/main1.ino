/*
    const int pin_E = 13;
    const int pin_D = 12;
    const int pin_C = 11;
    const int pin_DP = 10;
    const int pin_G = 9;
    const int pin_F = 8;
    const int pin_A = 7;
    const int pin_B = 6;

    const int pin_arr[] = {pin_A, pin_B, pin_C, pin_D, pin_E, pin_F, pin_G, pin_DP};
    const int num_arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    void print_num(int num);
    void clear_screen();

    void setup(){
        pinMode(pin_A, OUTPUT); pinMode(pin_B, OUTPUT); pinMode(pin_C, OUTPUT); pinMode(pin_D, OUTPUT); 
        pinMode(pin_E, OUTPUT); pinMode(pin_F, OUTPUT); pinMode(pin_G, OUTPUT); pinMode(pin_DP, OUTPUT);
    }

    void loop(){
        for(int i=0; i<10; i++){
            print_num(num_arr[i]);
            delay(1000);
        }
    }

    void print_num(int num){
        clear_screen();
        delay(500);
        for(int j=0; j<8; j++){
            int value = num & (1 << j);
            digitalWrite(pin_arr[j], value);
        }
    }

    void clear_screen(){
        for(int j=0; j<8; j++){
            digitalWrite(pin_arr[j], 0);
        }
    }
*/