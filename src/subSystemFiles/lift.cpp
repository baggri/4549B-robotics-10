#include "main.h"
 //help func
void setLift(int power) {
    lift = power;
}

//driver cont func
void setLiftMotor() {
    int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y));
    setLift(liftPower);
}
