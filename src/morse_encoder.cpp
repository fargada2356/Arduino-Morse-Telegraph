#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myLcd(0x27, 16, 2);


const uint8_t ledPin = 13;
const uint8_t buttonPin = 12;
const uint16_t segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void segmentArray(byte charArray) {

byte charArray[] = {

  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111, // 9
  B01110111, // A
  B01111100, // b (using lowercase to avoid confusion with 8)
  B00111001, // C
  B01011110, // d (using lowercase to avoid confusion with 0)
  B01111001, // E
  B01110001 // F

};


}



void setup() {

  for(int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }


  

}

void loop() {

  for(int i = 0; i < 16; i++) {
    displayCharacter
  }


}