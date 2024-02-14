// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SafeTeleopBatonSwingCmd.h"
#include <Constants.h>

SafeTeleopBatonSwingCmd::SafeTeleopBatonSwingCmd(frc::XboxController *pController, BatonSub *pBatonSub, ClimberSub *pClimbSub) 
{
  AddRequirements(pBatonSub);
  AddRequirements(pClimbSub);
  m_pController = pController;
  m_pBatonSub = pBatonSub;
  m_pClimbSub = pClimbSub;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SafeTeleopBatonSwingCmd::Initialize() 
{
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void SafeTeleopBatonSwingCmd::Execute() 
{
  if ((m_pBatonSub == nullptr) or (m_pController == nullptr) or (m_pClimbSub == nullptr))
  {
    m_isFinished = true; 
    return;
  }
  if (m_pClimbSub->IsAtRetractLimit() == true) //"Retract limit" is like batons "rest limit"
  {
    if (m_pController->GetLeftBumper() == true)
    {
      m_isFinished = m_pBatonSub->GoToRest();
    }
    else
    {
      m_isFinished = m_pBatonSub->GoToSwing();
    }
  }
  else
  {
    m_pClimbSub->Retract();
  }
  
}

// Called once the command ends or is interrupted.
void SafeTeleopBatonSwingCmd::End(bool interrupted) 
{
   if ((m_pBatonSub != nullptr) and (m_pClimbSub != nullptr))
  {
    m_pBatonSub->Stop();
    m_pClimbSub->Stop();
  }
}

// Returns true when the command should end.
bool SafeTeleopBatonSwingCmd::IsFinished() 
{
  return m_isFinished;
}
