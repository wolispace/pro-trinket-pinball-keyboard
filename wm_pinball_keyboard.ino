/*
   wm_pinball_keyboard
    20190609

  ProTrinketKeyboard example
  For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
  Please use library TrinketKeyboard for the ATtiny85 based Trinket
  Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/

#include <ProTrinketKeyboard.h>  // Ensure the library is installed
// Why not pin 13 - it repeats contantly?
// Switches are connected from ground to these defined pins
const int PIN_LEFT_FLIPPER = 12;
const int PIN_RIGHT_FLIPPER = 11;
const int PIN_LEFT_MAGNA = 10;
const int PIN_RIGHT_MAGNA = 9;
const int PIN_PLUNGER = 8;
const int PIN_START = 6;
const int PIN_NUDGE_UP = 5;

void setup()
{
  // Declare button pins as inputs
  pinMode(PIN_LEFT_FLIPPER, INPUT);
  pinMode(PIN_RIGHT_FLIPPER, INPUT);
  pinMode(PIN_LEFT_MAGNA, INPUT);
  pinMode(PIN_RIGHT_MAGNA, INPUT);
  pinMode(PIN_PLUNGER, INPUT);
  pinMode(PIN_START, INPUT);
  pinMode(PIN_NUDGE_UP, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_LEFT_FLIPPER, HIGH);
  digitalWrite(PIN_RIGHT_FLIPPER, HIGH);
  digitalWrite(PIN_LEFT_MAGNA, HIGH);
  digitalWrite(PIN_RIGHT_MAGNA, HIGH);
  digitalWrite(PIN_PLUNGER, HIGH);
  digitalWrite(PIN_START, HIGH);
  digitalWrite(PIN_NUDGE_UP, HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors

  if (digitalRead(PIN_LEFT_FLIPPER) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_A);
  }

  // release the last key if none of these are pressed
  if (digitalRead(PIN_LEFT_FLIPPER) == HIGH 
  && digitalRead(PIN_RIGHT_FLIPPER) == HIGH
  && digitalRead(PIN_LEFT_MAGNA) == HIGH
  && digitalRead(PIN_RIGHT_MAGNA) == HIGH
  && digitalRead(PIN_PLUNGER) == HIGH
  && digitalRead(PIN_START) == HIGH
  && digitalRead(PIN_NUDGE_UP) == HIGH
  ) {
    TrinketKeyboard.pressKey(0, 0);
  }
  
  if (digitalRead(PIN_RIGHT_FLIPPER) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_L);
  }
  if (digitalRead(PIN_LEFT_MAGNA) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_Q);
  }
  if (digitalRead(PIN_RIGHT_MAGNA) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_P);
  }
  if (digitalRead(PIN_PLUNGER) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_SPACE);
  }
  if (digitalRead(PIN_START) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_ENTER);
  }
  if (digitalRead(PIN_NUDGE_UP) == LOW) {
    TrinketKeyboard.pressKey(0, KEYCODE_W);
  }
  
}
