/*
  SevenSegment.cpp - Library for Seven Segment LED module.
  Created by Zain Ali, January 3rd, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SevenSegment.h"

SevenSegment::SevenSegment()
{
}

void SevenSegment::attach(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG)
{
  // Store pin segment sequence
  pin_array[0] = pinA;
  pin_array[1] = pinB;
  pin_array[2] = pinC;
  pin_array[3] = pinD;
  pin_array[4] = pinE;
  pin_array[5] = pinF;
  pin_array[6] = pinG;
  // Initialise pins
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void SevenSegment::attach(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int disp_type)
{
  attach(pinA, pinB, pinC, pinD, pinE, pinF, pinG);
  type(disp_type);
}

void SevenSegment::type(int disp_type)
{
  this->disp_type = disp_type;
}

void SevenSegment::interval(uint16_t interval_millis)
{
  this->interval_millis = interval_millis;
}

void SevenSegment::update()
{

  if ((millis() - previous_millis >= interval_millis) && (seg <= 7))
  {
    switch (state)
    {
      case LOOP:
        for (int j = 0 ; j < 7 ; j++)
        {
          updateDisplay(j, loop_array[seg][j]);
        }
        seg++;
        break;
      case WRITE:
        updateDisplay(seg, num_array[display_value][seg]);
        seg++;
        break;

      // Catchall case - Do nothing here
      case REST:
      default:
        return;
    }

    previous_millis = millis();
  }
  else if (seg > 7)
  {
      seg = 0;
      if(loops > 0)
      {
        loops--;
      }
      else
      {
        state = REST;
      }
  }
}

void SevenSegment::clear()
{
  reset();
  state = REST;
}

void SevenSegment::numWrite(int display_value)
{
  if (!(display_value >= 0 && display_value <= 9))
    return;
  this->display_value = display_value;
  reset();
  state = WRITE;
}

void SevenSegment::segLoop(int loops)
{
  this->loops = loops;
  reset();
  state = LOOP;
}

int SevenSegment::currentState()
{
  return state;
}

inline void SevenSegment::reset()
{
  for (seg = 0; seg < 7; seg++)
  {
    updateDisplay(seg, false); // Turn off all LEDS
  }
  seg = 0;
}

inline void SevenSegment::updateDisplay(int segment, bool value)
{
    if(segment < 0 || segment >= 7) return;
    switch (disp_type)
    {
      default:
      case COMMON_ANODE:
        digitalWrite(pin_array[segment], !value);
        break;
      case COMMON_CATHODE: 
        digitalWrite(pin_array[segment], value);
        break;
    }
  
}
