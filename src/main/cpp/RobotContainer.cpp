// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h" 
#include "commands/DriveCmd.h"
#include "commands/AmpShootCmd.h"
#include "commands/SpeakerShootCmd.h"
#include "commands/PickupNoteCmd.h"
#include "commands/BatonSwingCmd.h"

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
}

void RobotContainer::ConfigureBindings() {
  // Configure button bindings here

  // Loader Command
  m_driverController.B().WhileTrue(PickupNoteCmd(&m_loaderSub, &m_driverController).ToPtr());

  // Shooter Commands
  m_driverController.RightTrigger().WhileTrue(SpeakerShootCmd(&m_driverController, &m_shooterSub).ToPtr());
  m_driverController.RightBumper().WhileTrue(AmpShootCmd(0.75, &m_shooterSub).ToPtr());

  // Baton Command
  m_driverController.X().ToggleOnTrue(BatonSwingCmd(&m_batonSub, 0.1).ToPtr());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  switch (GetDPDT())
  {
    case 1:
      // position 2
      break;
    case 2:
      // position 3
      break;
    case 0:
    default:
      // position 1
      return autos::Position1CmdGrp(&m_driveSub, &m_visionSub, &m_shooterSub);
  }
}

int RobotContainer::GetDPDT() 
{
  return 0;
}

void RobotContainer::ZeroSensors()
{
  m_batonSub.ZeroSensors();
}
