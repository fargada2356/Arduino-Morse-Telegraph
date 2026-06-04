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

      void showDisplayMessage(String morseInput, char translatedLetter) {
        _lcd->setCursor(0, 0);
        _lcd->print("Msg: ");
        _lcd->print(morseInput);
        _lcd->print("     ");

        _lcd->setCursor(0, 1);
        _lcd->print("Input: ");
        _lcd->print(translatedLetter);
      }

};