#pragma once

#include <Arduino.h>

class Led {

  private:

      uint8_t ledPin;


  public:
  
      Led(uint8_t pin) : ledPin(pin) {}

      void begin() {
        pinMode(ledPin, OUTPUT);
      }

      void ledTurnOn() {
        digitalWrite(ledPin, HIGH);
      }
      void ledTurnOff() {
        digitalWrite(ledPin, LOW);
      }

};