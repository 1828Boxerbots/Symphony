// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BatonSwingCmd.h"
#include <Constants.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

BatonSwingCmd::BatonSwingCmd(BatonSub *pSub, double speed) 
{
  AddRequirements(pSub);
  m_pSub = pSub;
  m_Speed = speed;
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

  if (m_pSub->GetEncoderPos() >= -1.0 && m_pSub->GetEncoderPos() <= 1.0 && m_pSub->GetUpperHallTripped())
    m_Mode = BatonMovemementMode::EXTEND;
  else if (m_pSub->GetEncoderPos() >= 22.0 && m_pSub->GetEncoderPos() <= 23.0 && !m_pSub->GetUpperHallTripped())
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
    std::cout << "Running (UP)" << std::endl;

    if (!m_pSub->GetUpperHallTripped())
      m_Mode = BatonMovemementMode::STOP;

    break;
  case BatonMovemementMode::RETRACT:
    std::cout << "Running (DOWN)" << std::endl;

    // if (m_pSub->GetEncoderPos() >= 0.0 && m_pSub->GetEncoderPos() <= 1.0)
    //   m_Mode = BatonMovemementMode::STOP;

    break;
  case BatonMovemementMode::STOP:
    std::cout << "Finished" << std::endl;
    m_pSub->Stop();
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
    m_pSub->Stop();
  }
}

// Returns true when the command should end.
bool BatonSwingCmd::IsFinished() 
{
  return m_isFinished;
}
