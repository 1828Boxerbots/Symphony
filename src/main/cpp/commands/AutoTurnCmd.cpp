// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoTurnCmd.h"

AutoTurnCmd::AutoTurnCmd(DriveSub *pDrive, double absoluteAngle, double speed) 
{
  m_pDrive = pDrive;
  m_absoluteAngle = absoluteAngle;
  m_speed = speed;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDrive);
}

// Called when the command is initially scheduled.
void AutoTurnCmd::Initialize() 
{
  m_isFinished = false;

  if (m_pDrive == nullptr)
  {
    m_isFinished = true;
    return;
  }

}

// Called repeatedly when this Command is scheduled to run
void AutoTurnCmd::Execute() 
{
  if (m_pDrive == nullptr or m_isFinished == true)
  {
    m_isFinished = true;
    return;
  }

  m_pDrive->DriveTank(m_speed, -m_speed);
  m_isFinished = (m_pDrive->GetAngle() >= m_absoluteAngle);
}

// Called once the command ends or is interrupted.
void AutoTurnCmd::End(bool interrupted) 
{
  if (m_pDrive != nullptr)
  {
    m_pDrive->DriveTank(0.0, 0.0); // stop motors
  }
}

// Returns true when the command should end.
bool AutoTurnCmd::IsFinished() 
{
  return m_isFinished;
}
