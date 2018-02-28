/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SecretCommand.h"

SecretCommand::SecretCommand() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::grabber);
}

// Called just before this Command runs the first time
void SecretCommand::Initialize() {
	Robot::grabber->SetIntegrator(0);
}

// Called repeatedly when this Command is scheduled to run
void SecretCommand::Execute() {
	Robot::grabber->SetIntegrator(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool SecretCommand::IsFinished() {
	return !Robot::grabber->IsAtSwitch();
}

// Called once after isFinished returns true
void SecretCommand::End() {
	Robot::grabber->SetIntegrator(0);
	Robot::grabber->SetState(Kscale);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SecretCommand::Interrupted() {
	End();
}
