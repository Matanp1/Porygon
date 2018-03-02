/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/PIDSubsystem.h>
#include <WPILib.h>

using namespace frc;

class Chassis : public frc::PIDSubsystem {
private:
	/* CR: Bot */
	RobotDrive* matan_pro;
	ADXRS450_Gyro* gyroy;
	double rotfus;
	bool semi_auto;

public:
	Chassis();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;
	void Drive(double x, double y, double rotation);
	void Drive(double x, double y);
	void Drive(Joystick* stick);
	int GetAngle() const;
	void SetAuto(bool is_auto);
};

