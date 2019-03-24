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

void setup() {
  disp.attach(sPinA, sPinB, sPinC, sPinD, sPinE, sPinF, sPinG);

  //disp.type(COMMON_ANODE)
  // Blank out display
  disp.clear();
}

void loop() {
  int i;
  // Loop through segments animation x 2, 100 ms segment delay
  disp.segLoop(2,100);
  disp.clear();// Clear isplay

  // Write numbers with no delay
  for( i = 9; i >= 0 ; i--)
  {
    disp.numWrite(i);
    delay(500);
  }

  // Loop through segments animation 50 ms delay
  disp.segLoop(1,50);
  disp.clear(); // Clear isplay

  // Write numbers with segment delay 50ms
  for( i = 9; i >= 0 ; i--)
  {
    disp.numWrite(i,50);
    delay(500);
  }

}
