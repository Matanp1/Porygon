/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/CommandGroup.h>
#include <Commands/Throw.h>
#include <Commands/Delay.h>
#include <Commands/Shoot.h>
#include <Robot.h>

class Launch : public frc::CommandGroup {
public:
	Launch();
};

