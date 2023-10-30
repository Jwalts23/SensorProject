#include <Arduino.h>

class Button{
    public:
        
        Button(uint8_t Pin);
        void init();
        int read();
        bool isHigh();
        bool buttonPressed();
        
    protected:
        uint8_t pin;
};