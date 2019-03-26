Arduino SevenSegment 2.0.0
==========================

This library was made as a really quick and simple implementation for controlling a seven segment display.

Initialiser
-----------
 ```c++
 SevenSegment ()
 ```

Requires pin for segments A-G and type 

Type Definitions
-----------------
* COMMON_CATHODE 
* COMMON_ANODE

State Definitions
-----------------
* REST
* LOOP
* WRITE

Functions
---------
```c++
attach(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG) 
attach(int pinA,int pinB,int pinC,int pinD,int pinE,int pinF,int pinG, int disp_type)
type(int disp_type)
update()
interval(uint16_t interval_millis) 
numWrite(int display_value)
segLoop(int loops)
clear()
currentState()
```

Limitations
---------------------
* Supports common anode and cathode types
* Only controls the 7 segments (A -G)
* Update *MUST* be called every cycle for correct functioning

