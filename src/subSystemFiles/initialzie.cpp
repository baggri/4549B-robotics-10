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
  pros::lcd::set_text(0, "this is ggan bu.................");
  pros::lcd::set_text(1, "SEXYYYY");
  pros::lcd::set_text(2, "KillingBurf");
  pros::lcd::set_text(3, "TFT... we gonna drop the villian duh doo duh duh");
  pros::lcd::set_text(4, "too bees ....");
  pros::lcd::set_text(5, "in PBEEEE");


  driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  angler.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  intakeLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  pros::ADIGyro gyro('B', 0.91);
  pros::delay(2000);
}

void disabled() {}
