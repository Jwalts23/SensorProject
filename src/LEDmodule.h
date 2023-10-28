#include "constants.h"
#include "LED.h"

class LEDmodule{

    public:
        void init();
        void stopLight(int distance);
        void setThresholds(int thres1, int thres2);
    
    private:
        int threshold1;
        int threshold2;

        LED redLed = LED(RED_PIN);
        LED greenLed = LED(GREEN_PIN);
        LED yellowLed = LED(YELLOW_PIN);

        enum LedState{ Go, Caution, Stop };
        LedState ledState = Go;

};



// Set up LED Thresholds
// Made it so different sensors can easily have different threshold

