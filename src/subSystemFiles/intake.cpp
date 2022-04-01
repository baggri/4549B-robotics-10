#include "main.h"

void setIntake(int power) {
  intakeLeft = power;
  intakeRight = power;

}

void setIntakeMotors() {
  int intakePower = 0;

  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intakePower = -127;
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intakePower = 127;
  }

  setIntake(intakePower);
}
