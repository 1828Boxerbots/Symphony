// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h" 

#include "commands/TeleopShootCmd.h"
#include "commands/LoadCmd.h"
#include "commands/LoadUntilPhotogateCmd.h"
#include "commands/TeleopDriveCmd.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::Init()
{
  // TODO: As we start testing, incrementally enable each subsystem
  m_driveSub.Init();
  m_driveSub.SetDefaultCommand(TeleopDriveCmd(&m_driveSub, &m_driverController));

  //m_visionSub.Init();
  m_shooterSub.Init();
  //m_loaderSub.Init();
  //m_batonSub.Init();
  //m_climberSub.Init();
}

void RobotContainer::ConfigureBindings() {
  // Configure button bindings here

  // Loader Commands
  // m_driverController.A().WhileTrue(LoadUntilPhotogateCmd(&m_loaderSub, &m_driverController, 0.25).ToPtr());
  // m_driverController.B().WhileTrue(LoadCmd(&m_loaderSub, 0.25).ToPtr());

  // Shooter Command
  m_driverController.RightTrigger().WhileTrue(TeleopShootCmd(&m_driverController, &m_shooterSub).ToPtr());
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
