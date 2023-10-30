#include <Arduino.h>
#include "constants.h"
#include "LEDmodule.h"
#include "Photoresistor.h"
#include "Ultrasonic.h"
#include "Button.h"


LEDmodule leds = LEDmodule();

Photoresistor pResistor = Photoresistor(PHOTORESISTOR_PIN);
Ultrasonic ultrasonic = Ultrasonic(TRIGGER_PIN, ECHO_PIN);
Button button = Button(BUTTON_PIN);


void setup() {

  pResistor.init();
  ultrasonic.init();
  
  Serial.begin(9600);
}

boolean ultraMode = true;
float d;

void loop() {


  if(button.buttonPressed()){
    ultraMode =! ultraMode;
    delay(10);
    // Serial.println("button pressed");
    // Serial.println(ultraMode);
  }

  if(ultraMode){
    leds.setThresholds(5,30); // ultrasonic thresholds
    d = ultrasonic.distanceINcm();
  }else{
    leds.setThresholds(15,25);//presistor thresholds
    d = pResistor.read()/10;
  }

  leds.stopLight(d);
  delay(100);
  // Serial.println(d);
  // Serial.println(ledState); 
  // Serial.println(threshold2);
}




