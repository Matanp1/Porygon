/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ChangeIntegrator.h"

ChangeIntegrator::ChangeIntegrator() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
	power = (Robot::grabber->isAtScale()) ? DECLINE_POWER : LIFT_POWER;
	Robot::grabber->ChangeState();
}

// Called just before this Command runs the first time
void ChangeIntegrator::Initialize() {
	Robot::grabber->SetIntegrator(0);
}

// Called repeatedly when this Command is scheduled to run
void ChangeIntegrator::Execute() {
	Robot::grabber->SetIntegrator(power);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeIntegrator::IsFinished() {
	return Robot::grabber->IsAtSwitch();
}

// Called once after isFinished returns true
void ChangeIntegrator::End() {
	Robot::grabber->SetIntegrator(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeIntegrator::Interrupted() {
	End();
}
