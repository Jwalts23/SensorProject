#include "Arduino.h"

class Ultrasonic{
    public:
        uint8_t trigPin, echoPin;
        Ultrasonic(uint8_t TrigPin, uint8_t EchoPin);
        void init();

        
        float distanceINcm();
        float distanceINinches();
        
    private:
};