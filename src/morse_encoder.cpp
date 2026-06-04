#include <Arduino.h>
#include "Button.h"
#include "LCD.h"
#include "Led.h"
#include "Buzzer.h"
#include "segmentDisplay.h"

const byte displayPins[8] = {7, 6, 5, 4, 3, 2, 8, 9};

LiquidCrystal_I2C lcd(0x27, 16, 2);
LCD myLcd(&lcd);

Button myButton(12);
Buzzer myBuzzer(11);
Led myLed(13);
Segment mySegmentDisplay(displayPins);



void setup() {
 myLcd.begin();
 myButton.begin();
 myBuzzer.begin();
 myLed.begin();
 mySegmentDisplay.begin(); 
 Serial.begin(9600);
}

void loop() {

  static uint32_t lastReleaseTime = 0;
  static uint32_t startPressTime = 0;
  static uint16_t interval = 1000;
  static bool isPressed = false;
  static String currentMorse = "";
  static char finalLetter = ' ';
  static uint8_t myBuffer[16] = {0};

  uint8_t buttonState = digitalRead(12);

  if(buttonState == LOW) { // if button is held down
    myBuzzer.buzzerOn();
    if(isPressed == false) {
      startPressTime = millis();
      isPressed = true;
      myLed.ledTurnOn();
    }
}
   if(buttonState == HIGH && isPressed == true) {
    myBuzzer.buzzerOff();
    uint16_t duration = millis() - startPressTime;
    isPressed = false;
    myLed.ledTurnOff();

    lastReleaseTime = millis();

      if(duration > 300) {
        currentMorse += "-";
      }
      else if (duration > 50) {
        currentMorse += ".";
      }
   }

   if(buttonState == HIGH && currentMorse != "") {
    if(millis() - lastReleaseTime >= interval) {
      finalLetter = mySegmentDisplay.morseAlphabet(currentMorse);
      char letter = mySegmentDisplay.morseAlphabet(currentMorse);

      Serial.print("Translated letter: ");
      Serial.println(letter);

      mySegmentDisplay.segmentArray(letter, myBuffer);
      currentMorse = "";

      Serial.print("Sudurjanie na bufera: ");
      for(int i = 0; i < 8; i++) {
        Serial.print(String(myBuffer[i]));
      }
      Serial.println();
    }
   }

   for(int i = 0; i < 8; i++) {
    digitalWrite(displayPins[i], myBuffer[i]);
   }

    myLcd.showDisplayMessage(currentMorse, finalLetter);
}