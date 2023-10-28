#include "Button.h"

Button::Button(uint8_t Pin){
    pin = Pin;
}

void Button::init(){
    pinMode(pin, INPUT);
}

int Button::read(){
    return digitalRead(pin);
}

bool Button::isHigh(){
    bool isHigh = false;
    if (read() == 1){
        isHigh = true;
    }
    return isHigh;
}

