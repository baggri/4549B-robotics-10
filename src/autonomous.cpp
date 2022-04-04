#include "main.h"
void driveForward(int dist)
{

}

void redLeftCorner() {
  translate(-500, 100);
}

void blueLeftCorner() {
  translate(0, 0);
}

void redRightCorner() {
  translate(0, 0);
}

void blueRightCorner() {
  translate(0, 0);
}

void autonomous() {
  redLeftCorner();
  redRightCorner();
  blueLeftCorner();
  blueLeftCorner();
}
