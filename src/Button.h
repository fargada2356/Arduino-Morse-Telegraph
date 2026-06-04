#pragma once
#include <Arduino.h>

class Button {

  private:

      uint8_t buttonPin;
      uint8_t lastState = HIGH; // keeps track of the previous state 
      uint32_t pressStartTime = 0; // keeps track of when the button is held down


  public:
  
      Button(uint8_t pin) : buttonPin(pin) {}


      void begin() {
        pinMode(buttonPin, INPUT_PULLUP);
      }

      uint32_t getPressedDuration() {
        uint8_t buttonState = digitalRead(buttonPin);
        uint32_t duration = 0;

        if(buttonState == LOW && lastState == HIGH) {
          pressStartTime = millis();
        }

        if (buttonState == HIGH && lastState == LOW) {
          duration = millis() - pressStartTime;
        }

        lastState = buttonState;

        return duration;

      }

};