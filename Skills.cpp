#include "main.h"
#include "global.hpp"
#include "Auton/Skills.hpp"
#include "extra.hpp"

void Skills() {

    chassis.setPose(0, 0, -90);
    Wing.set_value(true);
    int startY1 = LeftDist.get();
    int startX1 = FrontDist.get();
    Intake.move_voltage(12000);
    chassis.moveToPoint(-22.2, 0, 700, {.maxSpeed = 75, .minSpeed = 25});
    chassis.moveToPoint(-48.8, 0, 2000, {.maxSpeed = 58, .minSpeed = 20});
    pros::delay(150);
    Match.set_value(true);
    pros::delay(500);
    Match.set_value(false);
    pros::delay(1040);
    int endY1 = LeftDist.get();
    int endX1 = FrontDist.get();
    int theta1 = imu1.get_heading() - 90;
    chassis.setPose((startX1-endX1)/25.4-84, (endY1-startY1)/25.4, theta1);
    chassis.swingToHeading(0, lemlib::DriveSide::LEFT, 1500, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 30});
    pros::delay(900);
    int X2 = LeftDist.get();
    chassis.setPose(X2/25.4-84, (endY1-startY1)/25.4, 0);

    // chassis.turnToHeading(0, 1500);
    // pros::delay(800);
    // chassis.setPose((startX1-endX1)/25.4-84, (endY1-startY1)/25.4, 0);

    chassis.moveToPoint(X2/25.4-84, -10, 1000, {.forwards = false, .maxSpeed = 75});
    pros::delay(800);
    int a1 = chassis.getPose().x;
    int a2 = chassis.getPose().y;
    chassis.setPose(a1, a2, 0);
    // imu1.set_heading(90);
    chassis.moveToPoint(-44.0, 38, 1000);
    pros::delay(700);
    Lift.set_value(true);
    chassis.turnToHeading(-135, 1000);
    chassis.moveToPoint(-29, 55, 1500, {.forwards = false});
    pros::delay(800);
    Hood.set_value(true);
    Stick.move_voltage(4400);
    pros::delay(1250);
    Stick.move_voltage(-4400);
    pros::delay(1250);
    Stick.move_voltage(0);
    chassis.moveToPoint(-63.8, 20, 1200, {.maxSpeed = 90});
    pros::delay(900);
    Match.set_value(true);
    Lift.set_value(false);
    Hood.set_value(false);
    chassis.turnToHeading(180, 900);
    chassis.moveToPoint(-63.8, 3, 2000, {.maxSpeed = 90});
    pros::delay(400);
    chassis.moveToPoint(-63.8, 20, 1000, {.forwards = false});
    chassis.turnToHeading(150, 1000);
    chassis.moveToPoint(-78, 35, 1000, {.forwards = false});
    pros::delay(800);
    Match.set_value(false);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-78, 95, 1600, {.forwards = false, .maxSpeed = 100});
    chassis.moveToPoint(-62, 110, 2500, {.forwards = false, .maxSpeed = 100});

    chassis.turnToHeading(0, 1000);

    pros::delay(1200);
    chassis.setPose(-62, 110, 0);
    chassis.moveToPoint(-62, 91, 1000, {.forwards = false, .maxSpeed = 100});
    pros::delay(1000);
    Hood.set_value(true);
    Stick.move_voltage(9000);
    pros::delay(650);
    Stick.move_voltage(-9000);
    pros::delay(650);
    Stick.move_voltage(0);
    Hood.set_value(false);
    Match.set_value(true);
    // int a3 = LeftDist.get();
    // chassis.setPose(a3/25.4-84, 91, 0);
    // imu1.set_heading(90);
    chassis.moveToPoint(-62.5, 132, 2000, {.maxSpeed = 80});
    pros::delay(2300);
    chassis.moveToPoint(-62.5, 91.5, 1600, {.forwards = false, .maxSpeed = 100});
    pros::delay(800);
    Stick.move_voltage(9000);
    pros::delay(650);
    Stick.move_voltage(-9000);
    pros::delay(650);
    Stick.move_voltage(0);
    Match.set_value(false);
    // int Y3 = FrontDist.get();
    int X3 = LeftDist.get();
    chassis.setPose(X3/25.4-84, 91.5, 0);
    // imu1.set_heading(90);
    chassis.moveToPoint(-62.5, 115, 2000, {.maxSpeed = 80});
    chassis.turnToHeading(70, 1000);
    chassis.moveToPoint(-38, 130, 1000, {.maxSpeed = 100});
    chassis.turnToHeading(90, 1000);
    pros::delay(600);
    
    int Y4 = 140-LeftDist.get()/25.4;
    chassis.setPose(-38, Y4, 90);
    chassis.moveToPoint(-14, Y4, 1400, {.maxSpeed = 80, .minSpeed = 30});
    chassis.moveToPoint(21.5, Y4, 1700, {.maxSpeed = 65, .minSpeed = 20});
    pros::delay(250);
    Match.set_value(true);
    pros::delay(350);
    Match.set_value(false);
    pros::delay(1090);
    int Y5= LeftDist.get();
    int X4 = FrontDist.get();
    chassis.setPose(58-X4/25.4, 133-Y5/25.4, imu1.get_heading()-90);
    
    chassis.swingToHeading(180, lemlib::DriveSide::LEFT, 1500, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .minSpeed = 30});
    pros::delay(1000);
    int X5 = LeftDist.get();
    chassis.setPose(58-X5/25.4, 133-Y5/25.4, 180);

    chassis.moveToPoint(58-X5/25.4, 133, 1000, {.forwards = false, .maxSpeed = 75});
    pros::delay(800);
    int a5 = chassis.getPose().x;
    int a6 = chassis.getPose().y;
    chassis.setPose(a5, a6, 180);
    // imu1.set_heading(90);
    chassis.moveToPoint(14, 91, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(-31.3, 91, 1600, {.forwards = false});
    chassis.turnToHeading(135, 1000);
    chassis.moveToPoint(-18.7, 73.5, 1500);
    pros::delay(800);
    IntakeLift.set_value(true);
    Intake.move_voltage(-3000);
    pros::delay(2500);
    chassis.moveToPoint(-32, 91, 1600, {.forwards = false});
    chassis.turnToPoint(40, 110, 3000);
    chassis.moveToPoint(40, 110, 3000, {.maxSpeed = 90});
    chassis.turnToHeading(180, 1600);
    pros::delay(600);
    Match.set_value(true);
    chassis.moveToPoint(40, 128, 1500);
    pros::delay(1000);
    chassis.moveToPoint(40, 91, 1600, {.forwards = false});
    pros::delay(400);
    Hood.set_value(true);
    pros::delay(300);
    Stick.move_voltage(9000);
    pros::delay(700);
    Stick.move_voltage(-9000);
    pros::delay(700);
    Stick.move_voltage(0);
    pros::delay(60000);

    return;
}
