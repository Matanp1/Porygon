/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/CommandGroup.h>
#include <Commands/RaiseToSwitch.h>
#include <Commands/SecretCommand.h>
#include <Robot.h>
class RaiseToScale : public frc::CommandGroup {
public:
	RaiseToScale(double power);
};
