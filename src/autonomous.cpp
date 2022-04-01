#include "main.h"

void redLeftCorner() {
  driveForward(500);
  turnLeft(500);

}

void blueLeftCorner() {

}

void redRightCorner() {

}

void blueRightCorner() {

}

void autonomous() {
  redLeftCorner();
  redRightCorner();
  blueLeftCorner();
  blueLeftCorner();
}
