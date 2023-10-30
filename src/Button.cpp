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

bool Button::buttonPressed() // Taster abfragen auf drücken des Buttons
{
  static boolean lastButtonState;
  boolean buttonState=read();
  if (buttonState!=lastButtonState) // Status hat sich geändert
  {
    lastButtonState=buttonState;  // letzten Status merken
    if (buttonState==HIGH) return true; // Status hat sich auf "gedrückt" geändert
  }
  return false;
}

