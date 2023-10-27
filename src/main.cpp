#include <Arduino.h>
#include "constants.h"
#include "LED.h"
#include "Photoresistor.h"


LED redLed = LED(RED_PIN);
LED greenLed = LED(GREEN_PIN);
LED yellowLed = LED(YELLOW_PIN);

Photoresistor pResistor = Photoresistor(PHOTORESISTOR_PIN);

// Set up LED Thresholds
// Made it so different sensors can easily have different thresholds
int* Threshold;
int threshold1 = Threshold[0];
int threshold2 = Threshold[1];
int pResistorThreshold[2] = {15 , 25};


enum LedState{ Go, Caution, Stop };
LedState ledState = Go;

void stopLight(int distance){
  switch(ledState) {
    case Go:
      greenLed.on();

      if (distance >= threshold1){
        greenLed.off();
        ledState = Caution;
      }
      break;

    case Caution:
      yellowLed.on();
     
      if (distance < threshold1){
        yellowLed.off();
        ledState = Go;
      }
     if (distance > threshold2){
        yellowLed.off();
        ledState = Caution;
      }
      break;

    case Stop:
      redLed.on();
      if (distance <= threshold2){
        redLed.off();
        ledState = Caution;
      }
      break;
  }
}

void setup() {
  redLed.init();
  greenLed.init();
  yellowLed.init();
  pResistor.init();
}

void loop() {
  int d = pResistor.read();
  Threshold = pResistorThreshold;
  stopLight(d);
  // put your main code here, to run repeatedly:
}




