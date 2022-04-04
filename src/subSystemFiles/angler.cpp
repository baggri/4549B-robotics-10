#include "main.h"

//pros::ADIPotentiator anglerPot('A');

//help func
void setAngler(int power) {
    angler = power;
}

//driver cont func
void setAnglerMotor() {
    int anglerPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    setAngler(anglerPower);

}
