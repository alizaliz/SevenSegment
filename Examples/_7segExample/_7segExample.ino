#include <SevenSegment.h>

// Seven segment display pins
const int sPinA = 3;
const int sPinB = 4;
const int sPinC = 5;
const int sPinD = 6;
const int sPinE = 7;
const int sPinF = 8;
const int sPinG = 9;

// Display
SevenSegment disp = SevenSegment();
int i = -1;
int num = 0;

void setup() {
  disp.attach(sPinA, sPinB, sPinC, sPinD, sPinE, sPinF, sPinG);

  disp.type(COMMON_ANODE);
  // Blank out display
  disp.clear();
  disp.interval(100);
}

void loop() {
  disp.update();

  if(disp.currentState() == REST)
  {
    i++;
  }
  
  if(i == 0)
  {
    // Loop through segments animation x 2, 100 ms segment delay
    disp.segLoop(2);
  }
  else if ( i > 0 && i <= 9)
  {
    disp.numWrite(i);
  }
  else
  {
    i = 0;
  }

}
