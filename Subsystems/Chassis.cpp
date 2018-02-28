/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Chassis.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Robot.h>
#include "../RobotMap.h"
#include "../Commands/DriveByJoystick.h"
#define CLIP(value) ((value >= -0.2 && value <= 0.2) ? 0 : value)

Chassis::Chassis() : PIDSubsystem("Chassis", 1.0, 0.0, 0.0) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	//SetSetpoint(0);
	this->rotfus = 0;
	this->semi_auto = false;
	this->gyroy = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
	this->gyroy->Reset();
	this->matan_pro = new RobotDrive(new VictorSP(CHASSIS_LEFT_FRONT), new VictorSP(CHASSIS_LEFT_REAR),
			new VictorSP(CHASSIS_RIGHT_FRONT), new VictorSP(CHASSIS_RIGHT_REAR));

	this->matan_pro->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor,true);
	this->matan_pro->SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor,true);
	this->matan_pro->SetSafetyEnabled(false);
	//Enable();
}

double Chassis::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	return int(this->gyroy->GetAngle()) % 360;
}

void Chassis::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	this->rotfus = output;
}

void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveByJoystick(Robot::stick));
}

void Chassis::Drive(double x, double y, double rotation)
{
	matan_pro->MecanumDrive_Cartesian(-CLIP(x), -CLIP(y),
							rotation, this->gyroy->GetAngle());
}
void Chassis::Drive(double x, double y)
{
	matan_pro->MecanumDrive_Cartesian(-CLIP(x), -CLIP(y),
								this->rotfus, this->gyroy->GetAngle());
}
void Chassis::Drive(Joystick* stick)
{
	double rotation = stick->GetRawAxis(2) - stick->GetRawAxis(3);
	if(semi_auto)
		rotation = this->rotfus;
	matan_pro->MecanumDrive_Cartesian(-CLIP(stick->GetX()), -CLIP(stick->GetY()),
			rotation, this->gyroy->GetAngle());
}

int Chassis::GetAngle() const
{
	return this->gyroy->GetAngle();
}
void Chassis::SetAuto(bool is_auto)
{
	this->semi_auto = is_auto;
}
