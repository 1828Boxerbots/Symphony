// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LoadUntilPhotogateCmd.h"

LoadUntilPhotogateCmd::LoadUntilPhotogateCmd(LoaderSub *pSub, double speed) 
{
  AddRequirements(pSub);
  m_pSub = pSub;
  m_speed = speed;

}

// Called when the command is initially scheduled.
void LoadUntilPhotogateCmd::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void LoadUntilPhotogateCmd::Execute() 
{
  if (m_pSub == nullptr)
  {
    m_isFinished = true; 
    return;
  }

  m_pSub->Load(m_speed);

  m_isFinished = m_pSub->GetPhotoGate();
}

// Called once the command ends or is interrupted.
void LoadUntilPhotogateCmd::End(bool interrupted) 
{
  m_pSub->Load(0.0);
}

// Returns true when the command should end.
bool LoadUntilPhotogateCmd::IsFinished() 
{
  return m_isFinished;
}
