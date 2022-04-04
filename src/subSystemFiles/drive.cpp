#include "main.h"

void setDrive(int left, int right) {
  driveLeftBack = left;
  driveLeftFront = left;
  driveRightBack = right;
  driveRightFront = right;
}

void resetDriveEncoders() {
  driveLeftBack.tare_position();
  driveLeftFront.tare_position();
  driveRightBack.tare_position();
  driveRightFront.tare_position();
}

void setDriveMotors() {
  int leftJoystick = controller.get_analog(pros:: E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros:: E_CONTROLLER_ANALOG_RIGHT_Y);

  if (abs(leftJoystick) < 10) {
    leftJoystick = 0;
  }

  if (abs(rightJoystick) < 10) {
    rightJoystick = 0;
  }

  setDrive(leftJoystick, rightJoystick);

}

void translate(int units, int voltage) {
  int direction = abs(units) / units;

  resetDriveEncoders();
  driveLeftBack.tare_position();

  while(fabs(driveLeftBack.get_position()) < abs(units)) {
    setDrive(voltage, voltage);
    pros::delay(10);
  }

  setDrive(-10, -10);
  pros::delay(50);

  setDrive(0, 0);
}
