#pragma once

#include "main.h"

void moveDist(int speed, int time);
double clamp(double v, double min, double max);
double wrapAngle(double angle);
double weightedIMUAngle(pros::Imu &imu1, pros::Imu &imu2, double wi, double w2);
double getHeading(pros::Imu *imu1, pros::Imu *imu2, double w1, double w2);
void driveLateralPID(double targetInches, double wheelDiameter);
void turnPIDEncoders( double targetDegrees, double wheelDiameter, double trackWidth, int timeoutMs);
void turnPID_1IMU(double targetDegrees, int timeoutMs);