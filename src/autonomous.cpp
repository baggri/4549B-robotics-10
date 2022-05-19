#include "main.h"

void redLeftCorner() {
  translate(1500, 100);
  pros::delay(12000);
  rotate(90, 127);
}

void blueLeftCorner() {
// okapi::ChassisController::moveDistance(1_m);
// Move 1 meter to the first goal

std::shared_ptr<ChassisController> chassis =
  ChassisControllerBuilder()
    .withMotors(11, 12, 13, 14)
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .build();
  // Move 1 meter to the first goal
  chassis->moveDistance(1_m);
  // Turn 90 degrees to face second goal
  chassis->turnAngle(90_deg);
  // Drive 1 and a half feet toward second goal
  chassis->moveDistance(1.5_ft);
}

void autonomous() {
  redLeftCorner();
/*   redRightCorner();
  blueLeftCorner();
  blueLeftCorner(); */
}