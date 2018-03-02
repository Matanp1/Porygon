/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RaiseIntegrator.h"

RaiseIntegrator::RaiseIntegrator() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
}

// Called just before this Command runs the first time
void RaiseIntegrator::Initialize() {
	Robot::grabber->SetIntegrator(0);
}

// Called repeatedly when this Command is scheduled to run
void RaiseIntegrator::Execute() {
	Robot::grabber->SetIntegrator(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseIntegrator::IsFinished() {
	return Robot::grabber->IsAtSwitch();
}

// Called once after isFinished returns true
void RaiseIntegrator::End() {
	Robot::grabber->SetIntegrator(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseIntegrator::Interrupted() {
	End();
}
