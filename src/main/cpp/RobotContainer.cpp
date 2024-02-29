// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/DriveCmd.h"
#include "commands/AmpShootCmd.h"
#include "commands/SpeakerShootCmd.h"
#include "commands/PickupNoteCmd.h"
#include "commands/SpitoutNoteCmd.h"
#include "commands/BatonSwingCmd.h"
#include "commands/VisionAlignCmd.h"

#include "commands/AutonomousPos1CmdGrp.h"
#include "commands/AutonomousPos2CmdGrp.h"
#include "commands/AutonomousPos3CmdGrp.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::Init()
{
  m_driveSub.Init();
  m_driveSub.SetDefaultCommand(DriveCmd(&m_driveSub, &m_driverController));

  m_visionSub.Init();
  m_shooterSub.Init();
  m_loaderSub.Init();
  m_batonSub.Init();
  //m_climberSub.Init();
  m_AutoSwitchSub.Init();
}

void RobotContainer::ConfigureBindings() {
  // Loader Commands
  m_driverController.B().ToggleOnTrue(PickupNoteCmd(&m_loaderSub, 0.7).ToPtr());
  m_driverController.Y().WhileTrue(SpitoutNoteCmd(&m_loaderSub, 0.7).ToPtr());

  // Shooter Commands
  m_driverController.RightTrigger().WhileTrue(SpeakerShootCmd(&m_driverController, &m_shooterSub, &m_loaderSub).ToPtr());
  m_driverController.LeftTrigger().WhileTrue(AmpShootCmd(0.7, &m_shooterSub, &m_loaderSub).ToPtr());

  // Baton Command
  m_driverController.A().OnTrue(BatonSwingCmd(&m_batonSub).ToPtr());

  // Auto Align Command
  m_driverController.X().OnTrue(VisionAlignCmd(&m_visionSub, &m_driveSub, 0.25).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  switch (m_AutoSwitchSub.GetSelectedMode())
  {
    case AutonomousMode::POS1:
      //AutonomousPos1CmdGrp(&m_driveSub).ToPtr();
      frc::SmartDashboard::PutString("Auto Mode", "Position 1");
      break;
    case AutonomousMode::POS2:
      //AutonomousPos2CmdGrp(&m_driveSub).ToPtr();
      frc::SmartDashboard::PutString("Auto Mode", "Position 2");
      break;
    case AutonomousMode::POS3:
      //AutonomousPos3CmdGrp(&m_driveSub).ToPtr();
      frc::SmartDashboard::PutString("Auto Mode", "Position 3");
      break;
  }
}

int RobotContainer::GetDPDT() 
{
  return 0;
}

void RobotContainer::ZeroSensors()
{
  m_batonSub.ZeroSensors();
  m_shooterSub.ZeroSensors();
  m_driveSub.ZeroSensors();
}
