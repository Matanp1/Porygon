/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "MakeScale.h"

MakeScale::MakeScale() {
	AddParallel(new Shoot());
	AddSequential(new Delay(2.5));
	AddSequential(new Throw());
}
