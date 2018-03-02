/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LowerIntegrator.h"

LowerIntegrator::LowerIntegrator() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
}

// Called just before this Command runs the first time
void LowerIntegrator::Initialize() {
	Robot::grabber->SetIntegrator(0);
}

// Called repeatedly when this Command is scheduled to run
void LowerIntegrator::Execute() {
	Robot::grabber->SetIntegrator(-0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool LowerIntegrator::IsFinished() {
	return Robot::grabber->IsAtSwitch();
}

// Called once after isFinished returns true
void LowerIntegrator::End() {
	Robot::grabber->SetIntegrator(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerIntegrator::Interrupted() {
	End();
}
