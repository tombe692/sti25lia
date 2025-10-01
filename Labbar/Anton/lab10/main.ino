/*
    const int sensor_pin = 13;
    const int motor_pin_fw = 11;
    const int motor_pin_bw = 10;

    typedef enum Door_enum{
        OPEN,
        OPEN_TO_CLOSED,
        CLOSED,
        CLOSED_TO_OPEN
    }Door_enum;

    Door_enum door_state = CLOSED;

    //unsigned long curr_time = 0;
    unsigned long set_time = 0;
    bool timer = false;
    int time_to_move_door = 1000;
    int duty = 0;

    void setup()
    {
        pinMode(sensor_pin, INPUT);
        pinMode(motor_pin_fw, OUTPUT);
        pinMode(motor_pin_bw, OUTPUT);

        Serial.begin(9600);
    }

    void loop()
    {
        switch(door_state){
            case(CLOSED):
                if(digitalRead(sensor_pin)){ door_state = CLOSED_TO_OPEN; }
                break;
            case(CLOSED_TO_OPEN):
                if(!timer){
                    set_time = millis();
                    timer = true;
                    duty = 255;
                    analogWrite(motor_pin_fw, duty);
                }
                if((millis() - set_time) >= time_to_move_door){
                    duty = 0;
                    analogWrite(motor_pin_fw, duty);
                    door_state = OPEN;
                    timer = false;
                }
                break;
            case(OPEN):
                if(digitalRead(sensor_pin) && duty == 0){ door_state = OPEN_TO_CLOSED; }
                break;
            case(OPEN_TO_CLOSED):
                if(!timer){
                    set_time = millis();
                    timer = true;
                    duty = 255;
                    analogWrite(motor_pin_bw, duty);
                }
                if((millis() - set_time) >= time_to_move_door){
                    duty = 0;
                    analogWrite(motor_pin_bw, duty);
                    door_state = CLOSED;
                    timer = false;
                }
                break;
            }
        Serial.println(door_state);
        delay(100);
    }
*/