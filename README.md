Arduino SevenSegment 1.0.0
==========================

This library was made as a really quick and simple implementation for controlling a seven segment display.

##Initialiser
* SevenSegment (int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int type)
Requires pin for segments A-G and type (COMMON_CATHODE or COMMON_ANODE)

##Functions
* numWrite(int number)
* numWrite(int number, int delay)
* clear()
* segLoop(int loops, int delay)
Number is the digit to be displayed. 
Delay is the delay in millisecods between pin writes.
Loops it the number of loops to animate.

##Limitations & Support
* Supports common anode and cathode types
* Only controls the 7 segments (A -G)
* All functions are blocking

