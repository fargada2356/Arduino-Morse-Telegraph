#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCD {

  private:

      LiquidCrystal_I2C* _lcd;

  public:
  
      LCD(LiquidCrystal_I2C* lcd) : _lcd(lcd) {}


      void begin() {
        _lcd->init();
        _lcd->backlight();
      }

      void showDisplayMessage() {
        
      }

};