#include "main.h"
#include "global.hpp"
#include "Auton/LeftElim.hpp"

void LeftElim() {
    chassis.setPose(0, 0, 0);
    Intake.move_voltage(12000);
    chassis.moveToPoint(-7, 26, 1000);
    pros::delay(550);
    Match.set_value(true);
    chassis.turnToHeading(-140, 800);
    chassis.moveToPoint(-34, 5, 1000);
    chassis.turnToHeading(-180, 800);
    pros::delay(1000);
    chassis.moveToPoint(-34.4, -13.7, 1000, {.maxSpeed = 80});
    pros::delay(950);
    chassis.moveToPoint(-34.4, 24, 1000, {.forwards = false, .maxSpeed=127});
    pros::delay(1000);
    Hood.set_value(true);
    Stick.move_voltage(9000);
    pros::delay(600);
    Stick.move_voltage(-9000);
    pros::delay(600);
    Stick.move_voltage(0);
    chassis.moveToPoint(-34.3, 13, 1000);
    pros::delay(500);
    Hood.set_value(false);
    chassis.cancelAllMotions();
    DriveL.move(-12.7*3);
    DriveR.move(-12.7*3);
    pros::delay(10000);
    return;
}