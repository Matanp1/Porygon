/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Throw.h"

Throw::Throw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
	SetTimeout(1);
}

// Called just before this Command runs the first time
void Throw::Initialize() {
	Robot::grabber->SetLeft(0);
	Robot::grabber->SetRight(0);
}

// Called repeatedly when this Command is scheduled to run
void Throw::Execute() {
	Robot::grabber->SetLeft(THROWER_POWER);
	Robot::grabber->SetRight(THROWER_POWER);
}

// Make this return true when this Command no longer needs to run execute()
bool Throw::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Throw::End() {
	Robot::grabber->SetLeft(0);
	Robot::grabber->SetRight(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Throw::Interrupted() {
	End();
}
