#include <Arduino.h>

#pragma once

class LED{
    
    public:
        uint8_t pin;

        LED(uint8_t pin);

        void init();
        void on();
        void off();

};