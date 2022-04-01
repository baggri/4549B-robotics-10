#include "main.h"

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed");
  } else {
    pros::lcd::clear_line(2);
  }
}

void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(0, "Hello PROS user!");

  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  angler.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void disabled() []
