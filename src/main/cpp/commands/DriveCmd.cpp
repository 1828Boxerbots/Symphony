// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCmd.h"

#include <iostream>

DriveCmd::DriveCmd(DriveSub *pDriveSub, frc::XboxController *pController) 
{
  m_pDriveSub = pDriveSub;
  m_pController = pController;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void DriveCmd::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void DriveCmd::Execute() 
{
  if (m_pDriveSub != nullptr && m_pController != nullptr)
  {
    double leftY = m_pController->GetLeftY();
    double rightX = m_pController->GetRightX();

    m_pDriveSub->DriveRC(-leftY, rightX);
  }
}

// Called once the command ends or is interrupted.
void DriveCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCmd::IsFinished() 
{
  return m_isFinished;
}
