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
  // Determines if output low or high to turn on LED Segment
  // if(type > 1 || type < 0)
  //   _type = COMMON_ANODE; // Default
  // else
  //   _type = type;

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

  if ((millis() - previous_millis >= interval_millis) && (seg < 7))
  {
    switch (state)
    {
      case LOOP:
        if (loops_complete < loops)
        {
          for (seg = 0; seg < 6; seg++)
          { // Outside segments - No G
            for (int k = 0; k < 7; k++)
            {
              if (k == seg)
              { // Activate Leds
                updateDisplay(seg, true);
              }
              else
              { // Deactivate LED
                updateDisplay(seg, false);
              }
            }
          }
        }
        loops_complete++;
        if(loops_complete >= loops)
        {
          loops_complete = 0;
          seg = 0;
          state = REST;
        }
        break;

      case WRITE:
        updateDisplay(seg, _num_array[display_value][seg]);
        seg++;
        break;
    
      case REST:
      default:
        return;
    }

    previous_millis = millis();
  }
  else if (seg >= 7)
  {
      seg = 0;
      state = REST;
  }
}

// Clear segments (turn all LEDs off)
void SevenSegment::clear()
{
  reset();
  state = REST;
}

// Write number immediately
void SevenSegment::numWrite(int display_value)
{
  if (!(display_value >= 0 && display_value <= 9))
    return;
  this->display_value = display_value;
  reset();
  state = WRITE;
}

// Loop through segments
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
  switch (disp_type)
  {
    default:
    case COMMON_ANODE:
      digitalWrite(pin_array[segment], value);
      break;
    case COMMON_CATHODE:
      digitalWrite(pin_array[segment], !value);
      break;
  }
}
