#pragma once

#include <Arduino.h>

class Segment {

  private:

      uint8_t pins[8]; // 3 4 5 6 7 8 9 10
      

  public:
  
      Segment(const uint8_t segmentPins[8]) {
        for(int i = 0; i < 8; i++) {
          pins[i] = segmentPins[i];
        }
      }


      void begin() {
        for(int i = 0; i < 8; i++) {
          pinMode(pins[i], OUTPUT);
        }
      }

      void segmentArray(char letter, uint8_t* charArray) {
        byte data[16] = {
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

        int8_t index = -1;
        if (letter >= '0' && letter <=  '9') index = letter - '0';
        else if (letter == 'A' || letter == 'a') index = 10;
        else if (letter == 'B' || letter == 'b') index = 11;
        else if (letter == 'C' || letter == 'c') index = 12;
        else if (letter == 'D' || letter == 'd') index = 13;
        else if (letter == 'E' || letter == 'e') index = 14;
        else if (letter == 'F' || letter == 'f') index = 15;

        if (index != -1) {
          byte encode = data[index];
          for(int i = 0; i < 8; i++) {
            charArray[i] = bitRead(encode, i);
          }
        } else {
            for(int i = 0; i < 8; i++) charArray[i] = 0;
          }
        }

      char morseAlphabet(const String& morseCode) {
        
        if (morseCode == ".-") return 'A';
        if (morseCode == "-...") return 'b';
        if (morseCode == "-.-.") return 'C';
        if (morseCode == "-..") return 'd';
        if (morseCode == ".") return 'E';
        if (morseCode == "..-.") return 'F';
        if (morseCode == "-----") return '0';
        if (morseCode == ".----") return '1';
        if (morseCode == "..---") return '2';
        if (morseCode == "...--") return '3';
        if (morseCode == "....-") return '4';
        if (morseCode == ".....") return '5';
        if (morseCode == "-....") return '6';
        if (morseCode == "--...") return '7';
        if (morseCode == "---..") return '8';
        if (morseCode == "----.") return '9';

        return '?';
      }

};