/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/CommandGroup.h>
#include <Commands/Chassic/Drive.h>
#include <Commands/Shooter/Launch.h>
#include "Commands/Grabber/ChangeIntegrator.h"
#include <WPILib.h>

#define TIME 1.0
class AutoMiddle : public frc::CommandGroup {
public:
	AutoMiddle();
};

