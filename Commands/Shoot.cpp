/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Shoot.h"
Shoot::Shoot() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::shooter);
	SetTimeout(4.0);
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	Robot::shooter->SetRight(0);
	Robot::shooter->SetLeft(0);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	Robot::shooter->SetRight(s_power);
	Robot::shooter->SetLeft(s_power);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Shoot::End() {
	Robot::shooter->SetRight(0);
	Robot::shooter->SetLeft(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}
