/*
  SevenSegment.h - Library for Seven Segment LED module.
  Created by Zain Ali, January 3rd, 2017.
  Released into the public domain.

  NOTE: This is a minimal library designed for common anode/cathode LED segment displays.
  Can display a single digit, clear segments or 'loading' animation.
*/
#ifndef SevenSegment_h
#define SevenSegment_h

#include "Arduino.h"

// Types of displays
#define COMMON_CATHODE 0
#define COMMON_ANODE 1

#define REST 0
#define LOOP 1
#define WRITE 2

/** The SevenSegment class. */
class SevenSegment
{
  public:
    //Initialiser
    SevenSegment();
    void attach(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG);
    void attach(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG, int disp_type);
    void type(int disp_type);
    void update();
    void interval(uint16_t interval_millis);
    void numWrite(int display_value); 
    void segLoop(int loops); 
    void clear(); 
    int currentState();

  protected:
   
    int disp_type = COMMON_CATHODE;
    int seg = 0;
    int loops = 0;
    int loops_complete = 0;
    int display_value = 0;
    uint16_t previous_millis = 0;
    uint16_t interval_millis = 0;
    int pin_array[7] = {0,1,2,3,4,5,6};
    int state = REST; 
    // Character matrix
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

  private:
    inline void reset();
    inline void updateDisplay(int segment, bool value);
        
};

#endif
