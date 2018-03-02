/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("Shooter")
{
	this->left_motor = new VictorSP(SHOOTER_LEFT_MOTOR);
	this->right_motor = new VictorSP(SHOOTER_RIGHT_MOTOR);

	this->right_motor->SetInverted(true);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::SetLeft(double power) const
{
	this->left_motor->Set(power);
}
void Shooter::SetRight(double power) const
{
	this->right_motor->Set(power);
}
