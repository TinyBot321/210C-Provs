#include "main.h"
#include "global.hpp"
#include "extra.hpp"

void moveDist(int speed, int inches) {
    double rpm = 450;
    double wheel = 3.25;
    double time = abs((inches/((rpm/60)*2*wheel*3.1415926))*(127/speed)*1000);
    if (inches < 0) speed = -speed;
    DriveL.move(speed);
    DriveR.move(speed);
    pros::delay(time);
    DriveL.move(0);
    DriveR.move(0);
}

double clamp(double v, double min, double max) {
    if (v > max) return max;
    if (v < min) return min;
    return v;
}

double wrapAngle(double angle) {
    while (angle > 180) angle -= 360;
    while (angle < -180) angle += 360;
    return angle;
}

double weightedIMUAngle(pros::Imu &imu1, pros::Imu &imu2, double w1, double w2) {
    double a1 = imu1.get_rotation();
    double a2 = imu2.get_rotation();
    if (fabs(a1 - a2) > 180) {
        if (a1 > a2) a2 += 360;
        else a1 += 360;
    }
    return (a1 * w1) + (a2 * w2);
}

double getHeading(pros::Imu *imu1, pros::Imu *imu2, double w1, double w2) {
    if (imu1 && imu2) {
        double a1 = imu1->get_rotation();
        double a2 = imu2->get_rotation();
        if (fabs(a1 - a2) > 180) {
            if (a1 > a2) a2 += 360;
            else a1 += 360;
        }
        return (a1 * w1) + (a2 * w2);
    }
    if (imu1) return imu1->get_rotation();
    if (imu2) return imu2->get_rotation();
    return 0; 
}

void driveLateralPID(double targetInches, double wheelDiameter) {
    double kP = 4.9;
    double kD = 9;

    double prevError = 0;

    V1.reset_position();

    double wheelCircumference = M_PI * wheelDiameter;
    int settleTime = 0;

    while (settleTime < 200) {
        double rotDeg = V1.get_position() / 100.0;
        double currentInches = (rotDeg / 360.0) * wheelCircumference;

        double error = targetInches - currentInches;
        double derivative = error - prevError;
        prevError = error;

        double power = (kP * error) + (kD * derivative);
        if (fabs(power) < 25 && fabs(error) > 0.75)
            power = (power > 0) ? 25 : -25;

        power = clamp(power, -127, 127);

        DriveL.move(power);
        DriveR.move(power);
        if (fabs(error) < 1)
            settleTime += 10;
        else
            settleTime = 0;

        pros::delay(10);
    }

    DriveL.move(0);
    DriveR.move(0);
    return;
}

void turnPIDEncoders( double targetDegrees, double wheelDiameter, double trackWidth, int timeoutMs) {
    double kP = 3; 
    double kD = 6;  

    double wheelCirc = M_PI * wheelDiameter;
    double turnDistance = (M_PI * trackWidth) * (targetDegrees / 360.0);
    double targetRotDeg = (turnDistance / wheelCirc) * 360.0;
    DriveL.tare_position();
    DriveR.tare_position();

    double prevError = targetRotDeg;

    unsigned long startTime = pros::millis();
    int settleTime = 0;

    while (settleTime < 150 || (pros::millis() - startTime) < (unsigned long)timeoutMs) {
        double leftPos = DriveL.get_position(); 
        double rightPos = DriveR.get_position();

        double error = targetRotDeg - ((fabs(leftPos) + fabs(rightPos)) / 2.0); 
        double derivative = error - prevError;
        prevError = error;

        double power = (kP * error) + (kD * derivative);
        if (fabs(power) < 20 && fabs(error) > 1.0)
            power = (power > 0) ? 20 : -20;

        power = clamp(power, -127, 127);

        DriveL.move(power);
        DriveR.move(-power);  
        if (fabs(error) < 2)
            settleTime += 10;
        else
            settleTime = 0;

        pros::delay(10);
    }

    DriveL.move(0);
    DriveR.move(0);
}

void turnPID_1IMU(double targetDegrees, int timeoutMs) {
    double kP = 2.6;
    double kD = 8.0;

    imu1.tare_rotation();

    double prevError = 0;
    int settleTime = 0;
    unsigned long startTime = pros::millis();

    while (settleTime < 200 &&
           (pros::millis() - startTime) < (unsigned long)timeoutMs) {

        double current = imu1.get_rotation();
        double error = wrapAngle(targetDegrees - current);

        double derivative = error - prevError;
        prevError = error;

        double power = (kP * error) + (kD * derivative);

        // Minimum power to overcome static friction
        if (fabs(power) < 18 && fabs(error) > 1.5)
            power = (power > 0) ? 18 : -18;

        power = clamp(power, -127, 127);

        DriveL.move(power);
        DriveR.move(-power);

        if (fabs(error) < 1.0)
            settleTime += 10;
        else
            settleTime = 0;

        pros::delay(10);
    }

    DriveL.move(0);
    DriveR.move(0);
}

// void turnPID_2IMU(double targetDegrees, int timeoutMs) {
//     double kP = 2.4;
//     double kD = 7.5;
//     imu1.tare_rotation();
//     imu2.tare_rotation();
//     double prevError = 0;
//     int settleTime = 0;
//     unsigned long startTime = pros::millis();
//     while (settleTime < 200 && (pros::millis() - startTime) < (unsigned long)timeoutMs) {
//         double current = weightedIMUAngle(imu1, imu2, 0.5, 0.5);
//         double error = wrapAngle(targetDegrees - current);
//         double derivative = error - prevError;
//         prevError = error;
//         double power = (kP * error) + (kD * derivative);
//         if (fabs(power) < 18 && fabs(error) > 1.5)
//             power = (power > 0) ? 18 : -18;
//         power = clamp(power, -127, 127);
//         DriveL.move(power);
//         DriveR.move(-power);
//         if (fabs(error) < 1.0)
//             settleTime += 10;
//         else
//             settleTime = 0;
//         pros::delay(10);
//     }
//     DriveL.move(0);
//     DriveR.move(0);
// }

void updateOdometry(pros::Rotation &verticalRot, pros::Imu *imu1, pros::Imu *imu2, double w1, double w2, double wheelDiam) {
    double headingDeg = getHeading(imu1, imu2, w1, w2);
    double headingRad = headingDeg * M_PI / 180.0;

    double rotDeg = verticalRot.get_position() / 100.0;
    double inches = (rotDeg / 360.0) * (M_PI * wheelDiam);

    double delta = inches - prevVertInches;
    prevVertInches = inches;

    odomX += delta * cos(headingRad);
    odomY += delta * sin(headingRad);
}

void moveToXY(pros::Imu *imu1, pros::Imu *imu2, double imuW1, double imuW2, double targetX, double targetY, double wheelDiam, int timeoutMs) {
    double kP_dist = 6.0;
    double kD_dist = 25.0;

    double kP_turn = 3.2;
    double kD_turn = 10.0;

    V1.reset_position();
    prevVertInches = 0;
    odomX = 0;
    odomY = 0;

    if (imu1) imu1->tare_rotation();
    if (imu2) imu2->tare_rotation();

    double prevDistError = 0;
    double prevTurnError = 0;

    int settleTime = 0;
    unsigned long start = pros::millis();

    while (settleTime < 200 &&
           pros::millis() - start < (unsigned long)timeoutMs) {

        updateOdometry(V1, imu1, imu2, imuW1, imuW2, wheelDiam);

        double dx = targetX - odomX;
        double dy = targetY - odomY;

        double distance = sqrt(dx*dx + dy*dy);
        double targetAngle = atan2(dy, dx) * 180.0 / M_PI;

        double heading = getHeading(imu1, imu2, imuW1, imuW2);
        double turnError = wrapAngle(targetAngle - heading);


        double distDeriv = distance - prevDistError;
        prevDistError = distance;

        double forward = kP_dist * distance + kD_dist * distDeriv;
        forward = clamp(forward, -100, 100);


        double turnDeriv = turnError - prevTurnError;
        prevTurnError = turnError;

        double turn = kP_turn * turnError + kD_turn * turnDeriv;
        turn = clamp(turn, -80, 80);


        DriveL.move(forward + turn);
        DriveR.move(forward - turn);


        if (distance < 0.75 && fabs(turnError) < 2)
            settleTime += 10;
        else
            settleTime = 0;

        pros::delay(10);
    }

    DriveL.move(0);
    DriveR.move(0);
}
