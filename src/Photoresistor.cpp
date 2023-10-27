#include "Photoresistor.h"

    Photoresistor::Photoresistor(uint8_t Pin){
        pin=Pin;
    }

    void Photoresistor::init(){
        pinMode(pin, INPUT);
    }
    
    int  Photoresistor::read(){
        return analogRead(pin);
    }   