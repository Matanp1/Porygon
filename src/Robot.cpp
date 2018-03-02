
/*----------------------------------------------------------------------------*/

/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Robot.h>
Chassis* Robot::chassis = nullptr;
Grabber* Robot::grabber = nullptr;
Shooter* Robot::shooter = nullptr;
frc::Joystick* Robot::driver_stick = nullptr;


void Robot::RobotInit() {
	//m_chooser.AddDefault("Default Auto", &m_defaultAuto);
	//m_chooser.AddObject("My Auto", &m_myAuto);
	//frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	//Initialize subsystems:

	chassis = new Chassis();
	grabber = new Grabber();
	shooter = new Shooter();
	driver_stick = new Joystick(DRIVER_JOYSTICK);

	for (size_t i = 0; i < 10; i++)
		this->buttons[i] = new JoystickButton(this->driver_stick, i + 1);
	this->buttons[JOYSTICK_BUTTON_L_BUMPER]->WhileHeld(new Grab());
	this->buttons[JOYSTICK_BUTTON_X]->WhenPressed(new ChangeIntegrator());
//	this->buttons[JOYSTICK_BUTTON_X]->WhenPressed(new LowerIntegrator());
//	this->buttons[JOYSTICK_BUTTON_Y]->WhenPressed(new RaiseIntegrator());
	this->buttons[JOYSTICK_BUTTON_R_BUMPER]->WhenPressed(new Launch());
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector",
			"Default");
	if (autoSelected == "My Auto") {
		//m_autonomousCommand = &m_myAuto;
	} else {
		//m_autonomousCommand = &m_defaultAuto;
	}

	m_autonomousCommand = m_chooser.GetSelected();

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	frc::SmartDashboard::PutBoolean("IsIn", grabber->IsIn());
	frc::SmartDashboard::PutBoolean("IsAtSwitch", grabber->IsAtSwitch());
	frc::SmartDashboard::PutBoolean("IsAtScale?", grabber->isAtScale());
}

void Robot::TestPeriodic() {
}
START_ROBOT_CLASS(Robot)
