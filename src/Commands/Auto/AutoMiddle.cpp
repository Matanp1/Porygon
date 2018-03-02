/*----------------------------------------------------------------------------*/
/* Copyright (wc) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoMiddle.h"

AutoMiddle::AutoMiddle() {
	char input[4];
	double x = 0.5, y = 0.5;
	while(DriverStation::GetInstance().GetGameSpecificMessage().empty())
		continue;
	strncpy(input, DriverStation::GetInstance().GetGameSpecificMessage().c_str(), sizeof(input));
	if(input[0] == 'L')
		x *= -1;
	AddParallel(new Drive(x, y), TIME);
	AddParallel(new ChangeIntegrator());
	AddSequential(new Launch());
}
