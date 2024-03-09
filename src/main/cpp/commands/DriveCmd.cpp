// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCmd.h"

#include <cmath>

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

    double deadzone = 0.05;

    double leftY = m_pController->GetLeftY();
    double rightX = m_pController->GetRightX();

    frc::SmartDashboard::PutNumber("Left Timer", (double)m_LeftTimer.Get());
    frc::SmartDashboard::PutNumber("Right Timer", (double)m_RightTimer.Get());

    if (leftY < deadzone && leftY > -deadzone)
    {
      leftY = 0.0;
      m_LeftTimer.Stop();
      m_LeftTimer.Reset();
    }
    else
      m_LeftTimer.Start();

    if (rightX < deadzone && rightX > -deadzone)
    {
      rightX = 0.0;
      m_RightTimer.Stop();
      m_RightTimer.Reset();
    }
    else
      m_RightTimer.Start();

    double leftFactor = std::lerp(0.0, 1.0, (double)m_LeftTimer.Get());
    // double rightFactor = std::lerp(0.0, 1.0, (double)m_RightTimer.Get());
    double rightFactor = 1.0;

    m_pDriveSub->DriveRC(-(leftY * leftFactor), rightX * rightFactor);
  }
}

// Called once the command ends or is interrupted.
void DriveCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCmd::IsFinished() 
{
  return m_isFinished;
}
