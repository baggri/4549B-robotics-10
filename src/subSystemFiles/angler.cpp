#include "main.h"

pros::ADIPotentiometer anglerPot('A');

//help func
void setAngler(int power) {
    angler = power;
}

//driver cont func
void setAnglerMotor() {
  int anglerPower = 0;

  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    anglerPower = 127;
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    anglerPower = 33;
  }

  setAngler(anglerPower);
}
