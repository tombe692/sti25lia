/*

    const int led_green = 13;
    const int led_yellow = 12;
    const int led_red = 8;

    int yellow_delay = 2000;
    int green_delay = 4000;
    int red_delay = 4000;

    typedef enum State_enum {
        TO_GREEN,
        TO_RED
    }State_enum;

    State_enum state = TO_GREEN;

    void init_trafic();

    void setup(){
        pinMode(led_green, OUTPUT);
        pinMode(led_yellow, OUTPUT);
        pinMode(led_red, OUTPUT);
        init_trafic();
    }

    void loop(){
        if(state == TO_GREEN){
            state = TO_RED;
            digitalWrite(led_yellow, HIGH);
            delay(yellow_delay);
            digitalWrite(led_red, LOW);
            digitalWrite(led_yellow, LOW);
            digitalWrite(led_green, HIGH);
            delay(green_delay);
        }
        else if(state == TO_RED){
            state = TO_GREEN;
            digitalWrite(led_yellow, HIGH); 
            digitalWrite(led_green, LOW);
            delay(yellow_delay);
            digitalWrite(led_yellow, LOW);
            digitalWrite(led_red, HIGH);
            delay(red_delay);
        }
    }

    void init_trafic(){
        digitalWrite(led_green, LOW);
        digitalWrite(led_yellow, LOW); 
        digitalWrite(led_red, HIGH); 
        delay(red_delay); // start delay
    }
*/