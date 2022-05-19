#include "main.h"

pros::ADIGyro gyro('B', 0.99);

void setDrive(int topRight, int topLeft, int bottomLeft, int bottomRight) {
  driveTopRight = topRight;
  driveTopLeft = topLeft;
  driveBottomLeft = bottomLeft;
  driveBottomRight = bottomRight;
}

void resetDriveEncoders() {
  driveTopRight.tare_position();
  driveTopLeft.tare_position();
  driveBottomLeft.tare_position();
  driveBottomRight.tare_position();
}

void DriveDirection () {
  
}

double avgDriveEncoderValue() {
  return((fabs(driveTopRight.get_position()) + 
  fabs(driveTopLeft.get_position()) + 
  fabs(driveBottomLeft.get_position()) + 
  fabs(driveBottomRight.get_position())) / 4);
}


//okapi
std::shared_ptr<ChassisController> chassis =
  ChassisControllerBuilder()
    .withMotors(11, 12, 13, 14)
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();

void setDriveMotors() {
  int LeftYJoystick = controller.get_analog(pros:: E_CONTROLLER_ANALOG_LEFT_Y);
  int LeftXJoystick = controller.get_analog(pros:: E_CONTROLLER_ANALOG_LEFT_X);
  int RightXJoystick = controller.get_analog(pros:: E_CONTROLLER_ANALOG_RIGHT_X);

  if (abs(LeftXJoystick) <= 10) {
    LeftXJoystick = 0;
  }

  if (abs(LeftYJoystick) <= 10) {
    LeftYJoystick = 0;
  }

  if abs(RightXJoystick) <= 10) {
    RightXJoystick = 0
  }

  

  setDrive(TopRight, TopLeft, BottomRight, BottomLeft);

}
//autonomous
void translate(int units, int voltage) {
  int direction = abs(units) / units;

  resetDriveEncoders();

  gyro.reset();

  while(avgDriveEncoderValue() < abs(units)) {
    setDrive(voltage * direction + gyro.get_value(), voltage * direction - gyro.get_value());
    pros::delay(10);
  }

  setDrive(-10 * direction , -10 * direction);
  pros::delay(50);

  setDrive(0, 0);
}

void rotate(int degrees, int voltage) {
  int direction = abs(degrees) / degrees;
  
  gyro.reset();

  while(fabs(gyro.get_value()) < abs(degrees * 10)) {
    setDrive(-voltage * direction, voltage * direction);
    pros::delay(10);
  }
//letting it lose momentum
  pros::delay(100);
//correcting if wrong
  if(fabs(gyro.get_value()) > abs(degrees * 10) - 50) {
      setDrive(-voltage * direction, voltage * direction);
      while(fabs(gyro.get_value()) > abs(degrees * 10)) {
        pros::delay(10);
      }
  } else if (fabs(gyro.get_value()) > abs(degrees * 10)) {
    setDrive(0.5 *  voltage * direction, 0.5 * -voltage * direction);
      while(fabs(gyro.get_value()) > abs(degrees * 10)) {
        pros::delay(10);
      }
  }
  //reset drive
  setDrive(0,0); 
}
