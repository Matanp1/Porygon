/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Drive.h"

Drive::Drive(double x, double y, int angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::chassis);
	this->x = x;
	this->y = y;
	//Robot::chassis->SetSetpoint(angle);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	Robot::chassis->Drive(0,0,0);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	Robot::chassis->Drive(this->x, this->y);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	Robot::chassis->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();
}
