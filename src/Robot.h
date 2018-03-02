/*
 * Robot.h
 *
 *  Created on: 18 áôáø× 2018
 *      Author: Neat Team
 */
#pragma once

#include <WPILib.h>
#include <TimedRobot.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/Chassis.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/Shooter.h"
#include <RobotMap.h>
#include "Commands/Grabber/Grab.h"
#include "Commands/Shooter/Launch.h"
#include "Commands/Grabber/ChangeIntegrator.h"
#include "Commands/Grabber/LowerIntegrator.h"
#include "Commands/Grabber/RaiseIntegrator.h"

class Robot : public frc::TimedRobot {
public:
	static Chassis* chassis;
	static Grabber* grabber;
	static Shooter* shooter;
	static frc::Joystick* driver_stick;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	//ExampleCommand m_defaultAuto;
	//MyAutoCommand m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::JoystickButton* buttons[10];
};
