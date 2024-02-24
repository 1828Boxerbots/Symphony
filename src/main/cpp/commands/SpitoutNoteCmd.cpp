// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SpitoutNoteCmd.h"
#include <frc/smartdashboard/SmartDashboard.h>

SpitoutNoteCmd::SpitoutNoteCmd(LoaderSub *pSub, double speed) 
{
  m_pSub = pSub;
  m_speed = speed;

  AddRequirements(m_pSub);
}

// Called when the command is initially scheduled.
void SpitoutNoteCmd::Initialize() 
{
  
}

// Called repeatedly when this Command is scheduled to run
void SpitoutNoteCmd::Execute() 
{
  if (m_pSub == nullptr)
    m_isFinished = true;

  m_pSub->Load(-m_speed);
}

// Called once the command ends or is interrupted.
void SpitoutNoteCmd::End(bool interrupted) 
{
  m_pSub->Load(0.0);
}

// Returns true when the command should end.
bool SpitoutNoteCmd::IsFinished() {
  return m_isFinished;
}
