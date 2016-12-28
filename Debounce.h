
#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"



/*
 Debounce class based on example
 modified 28 Dec 2016
 by Saul Castro

 
 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 modified 28 Dec 2012
 by Mike Walters
 

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Debounce
 */

class Debounce{
  public:
  Debounce(int inputPin){
    buttonPin = inputPin;
  }
  ~Debounce(){};
    void ini();
    int checkButton();
    
private: 

 int buttonPin = 2;    // the number of the pushbutton pin
 int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

};




#endif


