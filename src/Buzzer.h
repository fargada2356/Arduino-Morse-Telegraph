#pragma once

#include <Arduino.h>

class Buzzer {

  private:

      uint8_t _pin;

  public:
  
      Buzzer(uint8_t pin) : _pin(pin) {}

      void begin() {
        pinMode(_pin, OUTPUT);
        digitalWrite(_pin,  LOW);
      }

      void buzzerOn() {
        digitalWrite(_pin, HIGH);
      }

      void buzzerOff() {
        digitalWrite(_pin, LOW);
      }


};