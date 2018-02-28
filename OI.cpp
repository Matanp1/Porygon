/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

OI::OI() {
	this->driver_stick = new Joystick(DRIVER_JOYSTICK);
	this->operator_stick = new Joystick(OPERATOR_JOYSTICK);
	this->shoot_button = new JoystickButton(this->driver_stick, 1);
	this->switch_button = new JoystickButton(this->driver_stick, 2);
	for(size_t i = 0; i < 10; i++)
		this->buttons[i] = new JoystickButton(this->operator_stick, i + 1);

//	this->buttons[BTN_A]->WhenPressed(new MakeScale());
//	this->buttons[BTN_B]->WhenPressed(new RaiseToShooter(0.6));
}
Joystick* OI::GetDriver() const
{
	return this->driver_stick;
}
