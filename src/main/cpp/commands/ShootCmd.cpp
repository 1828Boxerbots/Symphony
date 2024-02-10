// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCmd.h"

ShootCmd::ShootCmd(double speed, ShooterSub *pShooterSub, VisionSub *pVisionSub) 
{
  AddRequirements(pShooterSub);
  AddRequirements(pVisionSub);
  m_pShooterSub = pShooterSub;
  m_pVisionSub = pVisionSub;
}

// Called when the command is initially scheduled.
void ShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootCmd::Execute() 
{
  m_speed = m_pShooterSub->CalculateSpeed((double)m_pVisionSub->GetTargDist(0)); //Remove parameter to get distance, there should not be a parameter
  if ((m_pShooterSub != nullptr) and (m_pVisionSub != nullptr))
  {
    m_pShooterSub->Shoot(m_speed); 
  }
  
  if (m_pShooterSub->GetSpeed() >= m_speed)
  {
    m_isFinished = true;
  }
}

// Called once the command ends or is interrupted.
void ShootCmd::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootCmd::IsFinished() {
  return m_isFinished;
}
