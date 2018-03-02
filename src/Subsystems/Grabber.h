/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <WPILib.h>
using namespace frc;

class Grabber : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* left_grabber;
	VictorSP* right_grabber;
	VictorSP* garry;
	DigitalInput* down_switch;
	DigitalInput* in_switch;
	DigitalInput* switch_position;
	bool grabber_state;
public:
	Grabber();
	void InitDefaultCommand() override;
	void SetLeft(double power) const;
	void SetRight(double power) const;
	void SetIntegrator(double power) const;
	bool IsUp() const;
	bool IsDown() const;
	bool IsIn() const;
	bool IsAtSwitch() const;
	bool isAtScale() const;
	void ChangeState();
};

