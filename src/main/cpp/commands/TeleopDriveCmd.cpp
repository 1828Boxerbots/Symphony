// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopDriveCmd.h"

TeleopDriveCmd::TeleopDriveCmd(DriveSub *pDriveSub, frc::XboxController *pController) 
{
  pDriveSub = m_pDriveSub;
  pController = m_pController;
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_pDriveSub);
}

// Called when the command is initially scheduled.
void TeleopDriveCmd::Initialize() 
{
}

// Called repeatedly when this Command is scheduled to run
void TeleopDriveCmd::Execute() 
{
  if (m_pDriveSub == nullptr and m_pController == nullptr)
  {
    m_yLeft = m_pController->GetLeftY();
    m_xRight = m_pController->GetRightX();

    m_pDriveSub->DriveRC(m_yLeft, m_xRight);
  }
}

// Called once the command ends or is interrupted.
void TeleopDriveCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool TeleopDriveCmd::IsFinished() 
{
  return m_isFinished;
}
