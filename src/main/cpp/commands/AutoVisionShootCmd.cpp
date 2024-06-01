// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoVisionShootCmd.h"

AutoVisionShootCmd::AutoVisionShootCmd(ShooterSub *pShooter, VisionSub *pVision) 
{
  m_pShooter = pShooter;
  m_pVision = pVision;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pShooter);
  AddRequirements(pShooter);
}

// Called when the command is initially scheduled.
void AutoVisionShootCmd::Initialize() 
{
  if (m_pVision == nullptr or m_pShooter == nullptr)
  {
    m_isFinished = true;
    return;
  }
  m_isFinished = false;
  double rangeToTarget = m_pVision->GetDistanceInMeters();
  m_speed = m_pShooter->CalculateSpeed(rangeToTarget);
}

// Called repeatedly when this Command is scheduled to run
void AutoVisionShootCmd::Execute() 
{
  if (m_pVision == nullptr or m_pShooter == nullptr or m_isFinished == true)
  {
    m_isFinished = true;
    return;
  }

  m_pShooter->Shoot(m_speed);
  if (m_pShooter->GetSpeed() >= m_speed)
  {
    m_isFinished = true;
    return;
  }
}

// Called once the command ends or is interrupted.
void AutoVisionShootCmd::End(bool interrupted) 
{
  // do NOT stop shooter here
}

// Returns true when the command should end.
bool AutoVisionShootCmd::IsFinished() 
{
  return m_isFinished;
}
