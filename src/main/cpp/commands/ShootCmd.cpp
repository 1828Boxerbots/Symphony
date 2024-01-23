// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCmd.h"

ShootCmd::ShootCmd(double speed, ShooterSub *pSub) 
{
  AddRequirements(pSub);
  m_speed = speed;
  m_pSub = pSub;
}

// Called when the command is initially scheduled.
void ShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() 
{
  if (m_pSub != nullptr)
  {
    m_pSub->Shoot(m_speed);
  }
  
  m_isFinished = true;
}

// Called once the command ends or is interrupted.
void ShootCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootCmd::IsFinished() {
  return m_isFinished;
}
