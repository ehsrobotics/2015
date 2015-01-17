#pragma config(Motor,  port1,           lift1,         tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           right,         tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           left,          tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           lift3,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           lift4,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           right2,        tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           left2,         tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          lift2,         tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "ehs.h"

void pre_auton() {
  bStopTasksBetweenModes = true; // LEAVE THIS SET TO TRUE - Barack Obama
}

task autonomous() {
	/* SIMULTANEOUS MOVEMENT TEST */
	step(-120, -120, 0, 4000);
	//step(getMoveRight(0, 0), getMoveLeft(0, 0), 0, 1000);
	//wait1Msec(1000);
	//step(getMoveRight(40, 0), getMoveLeft(40, 0), -100, 1000);
  //step(getMoveRight(-40, 0), getMoveLeft(-40, 0), -10, 1000);
	//step(getMoveRight(-40, 0), getMoveLeft(-40, 0), 5, 1400);
}


task usercontrol() {
	while (true) {
		if (vexRT[Ch4] == 0) {
			motor[right] = quadraticAcceleration(vexRT[Ch3]);
			motor[left] = quadraticAcceleration(vexRT[Ch3]);
		}
		else if (vexRT[Ch4] != 0){
			int ch4val = vexRT[Ch4];
			ch4val*=-1; // invert
			ch4val = ((float)ch4val) * 0.75; // lower sensitivity
			motor[right] = quadraticAcceleration(vexRT[Ch3]) - quadraticAccelerationGeneral(ch4val, 94);
			motor[left] = quadraticAcceleration(vexRT[Ch3]) + quadraticAccelerationGeneral(ch4val, 94);
			motor[right2] = quadraticAcceleration(vexRT[Ch3]) - quadraticAccelerationGeneral(ch4val, 94);
			motor[left2] = quadraticAcceleration(vexRT[Ch3]) + quadraticAccelerationGeneral(ch4val, 94);
		}
		liftManual(vexRT[Ch2]);
	}

}
