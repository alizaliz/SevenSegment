/*
  SevenSegment.cpp - Library for Seven Segment LED module.
  Created by Zain Ali, January 3rd, 2017.
  Released into the public domain.
*/


#include "Arduino.h"
#include "SevenSegment.h"


SevenSegment::SevenSegment()
{}

void SevenSegment::attach(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG)
{
    // Determines if output low or high to turn on LED Segment 
    // if(type > 1 || type < 0)
    //   _type = COMMON_ANODE; // Default
    // else
    //   _type = type; 

       // Store pin segment sequence
    _pin_array[0] = pinA;
    _pin_array[1] = pinB;
    _pin_array[2] = pinC;
    _pin_array[3] = pinD;
    _pin_array[4] = pinE;
    _pin_array[5] = pinF;
    _pin_array[6] = pinG;
    // Initialise pins
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
   
}

// Clear segments (turn all LEDs off)
void SevenSegment::clear(){
  for(int i = 0; i< 7; i++)
  {
    digitalWrite(_pin_array[i],_type); // Turn off all LEDS
  }
}

// Write number immediately
void SevenSegment::numWrite(int num)
{
  if (num >= 0 && num <= 9)
  for (int i=0; i < 7; i++) {
    if(_type == COMMON_CATHODE)
      digitalWrite(_pin_array[i], !_num_array[num][i]);
    else if (_type == COMMON_ANODE)
      digitalWrite(_pin_array[i], _num_array[num][i]);
  }
}

// Write number with delay(ms) between segment change
void SevenSegment::numWrite(int num, int ms)
{
  if (num >= 0 && num <= 9)
  for (int i=0; i < 7; i++) {
    // Match to LED matrix
    if(_type == COMMON_CATHODE)
      digitalWrite(_pin_array[i], !_num_array[num][i]);
    else if (_type == COMMON_ANODE)
      digitalWrite(_pin_array[i], _num_array[num][i]);
    delay(ms);
  }
}

// Loop through segments
void SevenSegment::segLoop(int loops, int ms)
{
  for(int i =0; i < loops; i ++){
    for( int j =0; j<6;j++){ // Outside segments - No G
      for (int k=0; k < 7; k++) {
        if(k == j) 
        { // Activate Leds
          if(_type == COMMON_CATHODE)
            digitalWrite(_pin_array[k],1); 
          else if (_type == COMMON_ANODE)
            digitalWrite(_pin_array[k],0);
          
        } 
        else 
        {  // Deactivate LED
          if(_type == COMMON_CATHODE)
            digitalWrite(_pin_array[k],0); 
          else if (_type == COMMON_ANODE)
            digitalWrite(_pin_array[k],1); 
        }
      }
      delay(ms);
    }
  }
}
