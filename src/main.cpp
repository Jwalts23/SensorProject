#include <Arduino.h>
#include "constants.h"
#include "LEDmodule.h"
#include "Photoresistor.h"
#include "Ultrasonic.h"


LEDmodule leds = LEDmodule();

Photoresistor pResistor = Photoresistor(PHOTORESISTOR_PIN);
Ultrasonic ultrasonic = Ultrasonic(TRIGGER_PIN, ECHO_PIN);


void setup() {

  pResistor.init();
  ultrasonic.init();
  
  Serial.begin(9600);
}

void loop() {
  float d;
  leds.setThresholds(15,25);//presistor thresholds
  d = pResistor.read()/10;

  leds.setThresholds(15,25); // ultrasonic thresholds
  d = ultrasonic.distanceINcm();
  



  leds.stopLight(d);
  delay(30);
  // Serial.println(d);
  // Serial.println(ledState); 
  // Serial.println(threshold2);
}




