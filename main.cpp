#include "main.h"
#include "global.hpp"
#include "lemlib/api.hpp"
#include "Auton/LeftElim.hpp"
#include "Auton/RightElim.hpp"
#include "Auton/SAWP.hpp"
#include "Auton/Skills.hpp"
#include "Auton/CounterSAWP.hpp"

void initialize() {
    pros::lcd::initialize();
	StickRot.reset_position();
	chassis.calibrate();
	
}

void on_center_button() {}

void disabled() {}

void competition_initialize() {}

int auton = 5;

void autonomous() {
	DriveL.set_brake_mode(MOTOR_BRAKE_COAST);
    DriveR.set_brake_mode(MOTOR_BRAKE_COAST);
    imu1.tare_heading();
    chassis.setPose(0, 0, 0);
	pros::Task screen_task([&]() {
		while (true) {
			pros::lcd::print(0, "X: %.2f", chassis.getPose().x); // x
			pros::lcd::print(1, "Y: %.2f", chassis.getPose().y); // y
			pros::lcd::print(2, "Theta: %.2f", chassis.getPose().theta);
			pros::lcd::print(3, "Theta(IMU): %.2f", imu1.get_heading());
			pros::delay(10);
		}
	});
	switch(auton){
		case 0:
			// None/PID
			break;
		case 1:
			// Left Elim
			LeftElim();
			break;
		case 2:
			// Right Elim
			RightElim();
			break;
		case 3:
			// SAWP
			SAWP();
			break;
		case 4:
			// Counter SAWP
			CounterSAWP();
			break;
		case 5:
			// Skills
			Skills();
			break;
	}
}

void opcontrol() {
	bool doubleParkState = false;
	bool LiftState = false;
	bool hoodState = true;
	bool matchloaderState = false;
	bool descoreState = false;
	IntakeLift.set_value(false);
	Hood.set_value(false);
	Stick.move_voltage(0);
	Intake.move_voltage(0);
	DriveL.move(0);
	DriveR.move(0);

	while (true) {

		if(master.get_digital(DIGITAL_R1) && master.get_digital(DIGITAL_R2)){
			//lift up
			if(LiftState == false && StickRot.get_position()/100 < 300){
				Intake.move_voltage(12000);
				Stick.move_voltage(12000);
				hoodState = true;
			}
			//lift down 
			else if(LiftState == true && StickRot.get_position()/100 < 290){
				Intake.move_voltage(12000);
				Stick.move_voltage(5400);
				hoodState = true;
			}
			else{
				Stick.brake();
				Stick.move_voltage(0);
				Intake.move_voltage(0);
			}

		} else if(master.get_digital(DIGITAL_R1)){ 
			hoodState = false;
			Intake.move_voltage(12000);
		} else if(master.get_digital(DIGITAL_R2)){
			hoodState = false;
			Intake.move_voltage(-8400);
		} else if(FrontLimit.get_value() == 1){
			Stick.move_voltage(0);
			StickRot.reset_position();
		} else if(abs(StickRot.get_position())/100 > 35){
			Stick.move_voltage(-6000); 
		} else {
			Intake.move_voltage(0);
			hoodState = false;
			Stick.move_voltage(0);
		}


		Hood.set_value(hoodState);

		if(master.get_digital_new_press(DIGITAL_B)){
			doubleParkState = !doubleParkState;
			Park.set_value(doubleParkState);
		}

		if(master.get_digital_new_press(DIGITAL_A)){
			matchloaderState = !matchloaderState;
			Match.set_value(matchloaderState);
		}

		if(master.get_digital_new_press(DIGITAL_L2)){
			LiftState = !LiftState;
			Lift.set_value(LiftState);
		}

		if(master.get_digital(DIGITAL_Y)){
			IntakeLift.set_value(true);
			Intake.move_voltage(-3000);
		} else {
			IntakeLift.set_value(false);
		}


		if (LiftState == false && master.get_digital(DIGITAL_L1)){
			descoreState = false;
		} else if(LiftState == false){
			descoreState = true;
		} else {
			descoreState = false;
		}

		Wing.set_value(descoreState);

		int dir = master.get_analog(ANALOG_LEFT_Y);    
		int turn = -master.get_analog(ANALOG_RIGHT_X) * 0.7;  
		DriveL.move(dir - turn);  
		DriveR.move(dir + turn);   
	       
		pros::delay(10);                      
	}
}         