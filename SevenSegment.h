/*
  SevenSegment.h - Library for Seven Segment LED module.
  Created by Zain Ali, January 3rd, 2017.
  Released into the public domain.

  NOTE: This is a basic library. Designed for common anode/cathode displays.
  Can display a single digit, clear segments or 'loading' animation.
*/
#ifndef SevenSegment_h
#define SevenSegment_h

#include "Arduino.h"

// Types of displays
#define COMMON_CATHODE 0
#define COMMON_ANODE 1

class SevenSegment
{
  public:
    SevenSegment(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG, int type);
    void Num_Write(int num);
    void Seg_Loop(int loops);
    void Clear();
  private:
    int _type;
    int _pin_array[7];
                             // a,b,c,d,e,f,g
    int _num_array[10][7] = { { 0,0,0,0,0,0,1 },    // 0
                              { 1,0,0,1,1,1,1 },    // 1
                              { 0,0,1,0,0,1,0 },    // 2
                              { 0,0,0,0,1,1,0 },    // 3
                              { 1,0,0,1,1,0,0 },    // 4
                              { 0,1,0,0,1,0,0 },    // 5
                              { 0,1,0,0,0,0,0 },    // 6
                              { 0,0,0,1,1,1,1 },    // 7
                              { 0,0,0,0,0,0,0 },    // 8
                              { 0,0,0,0,1,0,0 }};   // 9
                              
        
};

#endif
