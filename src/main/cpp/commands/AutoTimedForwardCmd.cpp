// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoTimedForwardCmd.h"

AutoTimedForwardCmd::AutoTimedForwardCmd(DriveSub *pDrive, units::time::second_t timeInSeconds, double speed) 
{
  m_pDrive = pDrive;
  m_timeInSeconds = timeInSeconds;
  m_speed = speed;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDrive);
}

// Called when the command is initially scheduled.
void AutoTimedForwardCmd::Initialize() 
{
    m_timer.Reset();
    m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoTimedForwardCmd::Execute() 
{
  if (m_pDrive == nullptr or m_timer.Get() >= m_timeInSeconds)
  {
    m_isFinished = true;
  }

  m_pDrive->DriveTank(m_speed, m_speed);
}

// Called once the command ends or is interrupted.
void AutoTimedForwardCmd::End(bool interrupted) 
{
  if (m_pDrive != nullptr)
  {
    m_pDrive->DriveTank(0.0, 0.0);
  }
  m_timer.Stop();
}

// Returns true when the command should end.
bool AutoTimedForwardCmd::IsFinished() 
{
  return false;
}
