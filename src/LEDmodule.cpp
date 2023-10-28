# include "LEDmodule.h"

void LEDmodule::init(){
    redLed.init();
    greenLed.init();
    yellowLed.init();  
}

void LEDmodule::setThresholds(int thres1, int thres2){
    threshold1=thres1;
    threshold2=thres2;
}


void LEDmodule::stopLight(int distance){
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
        ledState = Stop;
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