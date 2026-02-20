#include "main.h"
#include "global.hpp"
#include "Auton/Skills.hpp"

void Skills() {

    // chassis.turnToHeading(90, 5000);
    // pros::delay(1000);
    // // chassis.moveToPoint(24, 0, 5000);
    // // pros::delay(1000);
    // // chassis.moveToPoint(0, 0, 5000, {.forwards = false});
    // // pros::delay(1000);
    // chassis.turnToHeading(0, 5000);
    // pros::delay(15000);

    chassis.setPose(0, 0, -90);
    Intake.move_voltage(12000);
    chassis.moveToPoint(-41.2, 1, 5000, {.minSpeed = 50});
    pros::delay(960);
    Match.set_value(true);
    pros::delay(600);
    Match.set_value(false);
    pros::delay(300);
    chassis.setPose(-42.2, 1, -89);
    pros::delay(300);
    chassis.swingToHeading(0, lemlib::DriveSide::RIGHT, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 30});
    chassis.moveToPoint(-41.774, 36, 1000);
    chassis.turnToHeading(-135, 1000);
    pros::delay(700);
    Lift.set_value(true);
    chassis.moveToPoint(-25.028, 57.958, 1000, {.forwards = false});
    chassis.turnToHeading(-135, 500);
    pros::delay(800);
    chassis.setPose(-25.028, 57.958, -135);
    Hood.set_value(true);
    Intake.move_voltage(0);
    Stick.move_voltage(7000);
    pros::delay(700);
    Stick.move_voltage(-7000);
    pros::delay(700);
    Stick.move_voltage(0);
    Intake.move_voltage(12000);
    // chassis.moveToPoint(-58.183, 3.942, 5000);
    // chassis.moveToPoint(-62.064, 15.168, 5000); // middle of curve
    // chassis.moveToPoint(-49.971, 33.175, 5000);
    // chassis.turnToHeading(-135, 5000);
    // chassis.moveToPoint(-31.971, 51.175, 5000, {.forwards = false});
    // pros::delay(1500);
    // Intake.move_voltage(0);
    // Hood.set_value(true);
    // Stick.move_voltage(6000);
    // pros::delay(900);
    // Stick.move_voltage(-6000);
    // pros::delay(900);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);
    // chassis.moveToPoint(-35.951, 32.905, 5000);
    // pros::delay(800);
    // Hood.set_value(false);
    // chassis.moveToPoint(-1.926, 37.854, 5000);
    // chassis.moveToPoint(26.65, 15.19, 5000);
    // chassis.moveToPoint(26.65, 34, 5000, {.forwards = false});
    // pros::delay(1500);
    // Intake.move_voltage(0);
    // Hood.set_value(true);
    // Stick.move_voltage(6000);
    // pros::delay(900);
    // Stick.move_voltage(-6000);
    // pros::delay(900);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);

}