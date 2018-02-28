/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Grabber.h"
#include "../RobotMap.h"
#warning "Replace defualt state to scale"

Grabber::Grabber() :
		Subsystem("Grabber") {
	this->left_grabber = new VictorSP(GRABBER_LEFT_MOTOR);
	this->right_grabber = new VictorSP(GRABBER_RIGHT_MOTOR);
	this->garry = new VictorSP(GRABBER_GARRY_MOTOR);

	this->down_switch = new DigitalInput(GRABBER_DOWN_SWITCH);
	this->in_switch = new DigitalInput(GRABBER_IN_SWITCH);
	this->switch_position = new DigitalInput(GRABBER_SWITCH_POSITION);
	this->state = kGrab;
}

void Grabber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Grabber::SetLeft(double power) const {
	this->left_grabber->Set(power);
}
void Grabber::SetRight(double power) const {
	this->right_grabber->Set(power);
}
void Grabber::SetIntegrator(double power) const {
	this->garry->Set(power);
}
bool Grabber::IsDown() const {
	return !this->down_switch->Get();
}
bool Grabber::IsIn() const {
	return !this->in_switch->Get();
}
bool Grabber::IsAtSwitch() const {
	return !this->switch_position->Get();
}

State Grabber::GetState() const {
	return this->state;
}

void Grabber::SetState(State state) {
	this->state=state;
}

