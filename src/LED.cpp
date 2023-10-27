#include <LED.h>


    

    LED::LED(uint8_t Pin){
        pin = Pin;
    }

    void LED::init(){
        pinMode(pin, OUTPUT);
    }

    void LED::on(){
        digitalWrite(pin, HIGH);
    }
    void LED::off(){
        digitalWrite(pin, LOW);
    }
