/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Grab.h"

Grab::Grab() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
}

// Called just before this Command runs the first time
void Grab::Initialize() {
	Robot::grabber->SetLeft(0.0);
	Robot::grabber->SetRight(0.0);
}

// Called repeatedly when this Command is scheduled to run
void Grab::Execute() {
	Robot::grabber->SetLeft(0.4);
	Robot::grabber->SetRight(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool Grab::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Grab::End() {
	Robot::grabber->SetLeft(0.0);
	Robot::grabber->SetRight(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Grab::Interrupted() {
	End();
}
