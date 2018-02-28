/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LowerToCollect.h"

LowerToCollect::LowerToCollect(double power) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
	this->power = -power;
}

// Called just before this Command runs the first time
void LowerToCollect::Initialize() {
	Robot::grabber->SetIntegrator(0);
}

// Called repeatedly when this Command is scheduled to run
void LowerToCollect::Execute() {
	Robot::grabber->SetIntegrator(this->power);
}

// Make this return true when this Command no longer needs to run execute()
bool LowerToCollect::IsFinished() {
	return Robot::grabber->IsDown();
}

// Called once after isFinished returns true
void LowerToCollect::End() {
	Robot::grabber->SetIntegrator(0);
	Robot::grabber->SetState(kGrab);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerToCollect::Interrupted() {
	End();
}
