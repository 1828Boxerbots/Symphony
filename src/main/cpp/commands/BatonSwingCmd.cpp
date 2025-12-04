// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/BatonSwingCmd.h"

BatonSwingCmd::BatonSwingCmd(bool restFlag, BatonSub *pSub) 
{
  AddRequirements(pSub);
  m_flag = restFlag;
  m_pSub = pSub;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void BatonSwingCmd::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void BatonSwingCmd::Execute() 
{
  if (m_pSub == nullptr)
  {
    m_isFinished = true; 
    return;
  }
  if (m_flag == true)
  {
    m_isFinished = m_pSub->GoToRest();
    
  }
  else
  {
    m_isFinished = m_pSub->GoToSwing();
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

