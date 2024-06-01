// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoTimerCmd.h"

AutoTimerCmd::AutoTimerCmd(units::second_t timeoutInSeconds) 
{
    m_timeInSeconds = timeoutInSeconds;
    // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoTimerCmd::Initialize() 
{
    m_isFinished = false;
    m_timer.Reset();
    m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoTimerCmd::Execute() 
{
  m_isFinished = (m_timer.Get() > m_timeInSeconds);
}

// Called once the command ends or is interrupted.
void AutoTimerCmd::End(bool interrupted) 
{

}

// Returns true when the command should end.
bool AutoTimerCmd::IsFinished() 
{
  return m_isFinished;
}
