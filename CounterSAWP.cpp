#include "main.h"
#include "global.hpp"
#include "Auton/SAWP.hpp"

void CounterSAWP() {
    // Counter SAWP
    chassis.setPose(0, 0, -90);
    Lift.set_value(false);
    Hood.set_value(false);
    Intake.move_voltage(12000);
    // Move forward
    chassis.moveToPoint(-10, 0, 400);
    // Backward into the long goal
    chassis.moveToPoint(47.0, 0.5, 1400, {.forwards = false, .maxSpeed=110});
    pros::delay(650);
    Match.set_value(true);
    // Turn to face match loader
    chassis.turnToHeading(177, 780);
    // Go into matchloader
    chassis.moveToPoint(47.5, -15.3, 900, {.maxSpeed=110});
    pros::delay(600);
    // Back into long goal
    chassis.moveToPoint(47.5, 24, 1000, {.forwards = false, .maxSpeed=127});
    pros::delay(800);
    // Score
    Intake.move_voltage(0);
    Hood.set_value(true);
    Stick.move_voltage(12000);
    pros::delay(430);
    Stick.move_voltage(-8000);
    pros::delay(500);
    Stick.move_voltage(0);
    Intake.move_voltage(12000);
    Match.set_value(false);

    chassis.moveToPoint(47.5, 16, 500, {.maxSpeed=110});
    chassis.swingToHeading(-70, lemlib::DriveSide::RIGHT, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed=70 });
    pros::delay(200);
    Hood.set_value(false);
    // Go to middle 3
    chassis.moveToPoint(18, 28.5, 900, {.maxSpeed=110});
    pros::delay(300);
    // Lift.set_value(true);
    Match.set_value(true);
    pros::delay(300);
    Match.set_value(false);
    // Go to other 3
    chassis.moveToPoint(-30, 28.5, 900, {.maxSpeed=110});
    pros::delay(890);
    Match.set_value(true);
    Hood.set_value(true);
    chassis.moveToPoint(-49, 5, 1000, {.maxSpeed=110});
    chassis.turnToHeading(180, 5000);
    chassis.moveToPoint(-49, 22, 1000, {.forwards = false});
    pros::delay(850);
    Intake.move_voltage(0);
    Stick.move_voltage(7000);
    pros::delay(500);
    Stick.move_voltage(-7000);
    pros::delay(500);
    Stick.move_voltage(0);
    Intake.move_voltage(12000);
   
    
    
    // // Middle goal
    // chassis.moveToPoint(-12.4, 41, 900, {.forwards = false, .maxSpeed=110});
    // chassis.turnToHeading(-135, 300, {.minSpeed=30});
    // pros::delay(550);
    // chassis.setPose(-12.4, 41, -135);
    // // Score
    // Intake.move_voltage(0);
    // Stick.move_voltage(7000);
    // pros::delay(500);
    // Stick.move_voltage(-7000);
    // pros::delay(500);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);
    // Lift.set_value(false);
    // chassis.moveToPoint(-49, 5, 1000, {.maxSpeed=110});
    // chassis.turnToHeading(180, 5000);
    // chassis.moveToPoint(-49, -14.7, 1000);
    // pros::delay(1000);
    // chassis.moveToPoint(-49, 22, 1000, {.forwards = false});
    // pros::delay(850);
    // Intake.move_voltage(0);
    // Stick.move_voltage(7000);
    // pros::delay(500);
    // Stick.move_voltage(-7000);
    // pros::delay(500);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);




    // chassis.setPose(1.3, 0, -90);
    // Lift.set_value(false);
    // Hood.set_value(false);
    // Intake.move_voltage(12000);
    // // Move forward
    // chassis.moveToPoint(-10, 0, 400);
    // // Backward into the long goal
    // chassis.moveToPoint(47.0, 0, 1400, {.forwards = false, .maxSpeed=110});
    // pros::delay(650);
    // Match.set_value(true);
    // // Turn to face match loader
    // chassis.turnToHeading(177, 780);
    // // Go into matchloader
    // chassis.moveToPoint(47.5, -15.3, 900, {.maxSpeed=110});
    // pros::delay(600);
    // // Back into long goal
    // chassis.moveToPoint(47.5, 24, 1000, {.forwards = false, .maxSpeed=127});
    // pros::delay(800);
    // // Score
    // Intake.move_voltage(0);
    // Hood.set_value(true);
    // Stick.move_voltage(12000);
    // pros::delay(430);
    // Stick.move_voltage(-8000);
    // pros::delay(500);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);
    // Match.set_value(false);
    // // Turn to middle 3
    // chassis.moveToPoint(47.5, 16, 500, {.maxSpeed=110});
    // chassis.swingToHeading(-70, lemlib::DriveSide::RIGHT, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed=70 });
    // pros::delay(200);
    // Hood.set_value(false);
    // // Go to middle 3
    // chassis.moveToPoint(18, 27.5, 900, {.maxSpeed=110});
    // pros::delay(300);
    // Lift.set_value(true);
    // // Go to other 3
    // chassis.moveToPoint(-32.6, 27.6, 900, {.maxSpeed=110});
    // pros::delay(890);
    // Match.set_value(true);
    // Hood.set_value(true);
    // // Middle goal
    // chassis.moveToPoint(-15.4, 44, 900, {.forwards = false, .maxSpeed=110});
    // chassis.turnToHeading(-135, 300, {.minSpeed=30});
    // pros::delay(550);
    // chassis.setPose(-15.4, 44, -135);
    // // Score
    // Intake.move_voltage(0);
    // Stick.move_voltage(7000);
    // pros::delay(500);
    // Stick.move_voltage(-7000);
    // pros::delay(500);
    // Stick.move_voltage(0);
    // Intake.move_voltage(12000);
    // // Go to far matchloader
    // chassis.moveToPoint(-49.7, 10, 1000, {.maxSpeed=110, .minSpeed=30});
    // pros::delay(400);
    // Match.set_value(true);
    // Hood.set_value(false);
    // Lift.set_value(false);
    // // Turn
    // chassis.turnToHeading(180, 800);
    // pros::delay(850);
    // chassis.setPose(-49.7, 10, 180);
    // // Go into matchloader
    // chassis.moveToPoint(-51.5, -16, 1000, {.maxSpeed=110});
    // pros::delay(750);
    // Hood.set_value(true);
    // // Back into far long goal
    // chassis.moveToPoint(-51.5, 35, 1000, {.forwards = false, .maxSpeed=110});
    // pros::delay(700);
    // // Score
    // Intake.move_voltage(0);
    // Stick.move_voltage(12000);
    // pros::delay(400);
    // Stick.move_voltage(-6000);
    // pros::delay(500);
    // Stick.move_voltage(0);
    return;
}