// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BatonSwingCmd.h"
#include <Constants.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

BatonSwingCmd::BatonSwingCmd(BatonSub *pSub) 
{
  m_pSub = pSub;

  AddRequirements(m_pSub);
}

// Called when the command is initially scheduled.
void BatonSwingCmd::Initialize() 
{
  // Check that the subsystem is setup
  if ((m_pSub == nullptr))
  {
    m_isFinished = true; 
    return;
  }

  m_isFinished = false;

  if (m_pSub->GetUpperHallTripped() && m_pSub->GetAvgEncoderPos() <= 1.0)
  {
    m_Mode = BatonMovemementMode::EXTEND;
  }
  else if (!m_pSub->GetUpperHallTripped() || m_pSub->GetAvgEncoderPos() >= 21.0)
    m_Mode = BatonMovemementMode::RETRACT;
  else
    m_Mode = BatonMovemementMode::STOP;
}

// Called repeatedly when this Command is scheduled to run
void BatonSwingCmd::Execute() 
{
  switch (m_Mode)
  {
  case BatonMovemementMode::EXTEND:
    m_pSub->SetPosition(22.0);

    if (!m_pSub->GetUpperHallTripped() || m_pSub->GetAvgEncoderPos() >= 22.0)
      m_Mode = BatonMovemementMode::STOP;

    break;
  case BatonMovemementMode::RETRACT:
    m_pSub->SetPosition(0.0);

    if (m_pSub->GetAvgEncoderPos() <= 0.5)
      m_Mode = BatonMovemementMode::STOP;

    break;
  case BatonMovemementMode::STOP:
    m_pSub->SetMotors(0.0);
    m_isFinished = true;
    break;
  default:
    m_isFinished = true;
    break;
  }
}

// Called once the command ends or is interrupted.
void BatonSwingCmd::End(bool interrupted) 
{
   if (m_pSub != nullptr)
  {
    m_pSub->SetMotors(0.0);
  }
}

// Returns true when the command should end.
bool BatonSwingCmd::IsFinished() 
{
  return m_isFinished;
}
