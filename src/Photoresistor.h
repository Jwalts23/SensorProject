#include <Arduino.h>

class Photoresistor{

    public:
        uint8_t pin;

        Photoresistor(uint8_t Pin);
        void init();
        int  read();

    private:
    
};

