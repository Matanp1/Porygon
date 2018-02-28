/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <WPILib.h>
#include <RobotMap.h>
#include <Commands/Grab.h>
//#include <Commands/LowerToCollect.h>
//#include <Commands/MakeScale.h>
//#include <Commands/RaiseToShooter.h>
//#include <Commands/Throw.h>

using namespace frc;

#define BTN_A (0)
#define BTN_B (1)
#define BTN_X (2)
#define BTN_Y (3)
#define BTN_L (4)
#define BTN_R (5)
#define BTN_SELECT (6)
#define BTN_START (7)
#define BTN_L_STICK (8)
#define BTN_R_STICK (9)

class OI {
private:
	Joystick* driver_stick;
	Joystick* operator_stick;
	JoystickButton* buttons[10];
	JoystickButton* shoot_button;
	JoystickButton* switch_button;
public:
	OI();
	Joystick* GetDriver() const;
};
