// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AmpShootCmd.h"

AmpShootCmd::AmpShootCmd(double speed, ShooterSub *pSub) 
{
  AddRequirements(pSub);
  m_speed = speed;
  m_pSub = pSub;
}

// Called when the command is initially scheduled.
void AmpShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AmpShootCmd::Execute() 
{
  if (m_pSub == nullptr)
  {
    m_isFinished = true;
  }
  
  m_pSub->Shoot(-m_speed);
}

// Called once the command ends or is interrupted.
void AmpShootCmd::End(bool interrupted) \
{
  m_pSub->Shoot(0.0);
}

// Returns true when the command should end.
bool AmpShootCmd::IsFinished() {
  return m_isFinished;
}
