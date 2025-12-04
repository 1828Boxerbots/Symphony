// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopBatonSwingCmd.h"
#include <Constants.h>

TeleopBatonSwingCmd::TeleopBatonSwingCmd(frc::XboxController *pController, BatonSub *pSub) 
{
  AddRequirements(pSub);
  m_pController = pController;
  m_pSub = pSub;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TeleopBatonSwingCmd::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void TeleopBatonSwingCmd::Execute() 
{
  if ((m_pSub == nullptr) or (m_pController == nullptr))
  {
    m_isFinished = true; 
    return;
  }
  if (m_pController->GetLeftBumper() == true)
  {
    m_pSub->GoToRest();
  }
  else
  {
    m_pSub->GoToSwing();
  }
}

// Called once the command ends or is interrupted.
void TeleopBatonSwingCmd::End(bool interrupted) 
{
   if (m_pSub != nullptr)
  {
    m_pSub->Stop();
  }
}

// Returns true when the command should end.
bool TeleopBatonSwingCmd::IsFinished() 
{
  return m_isFinished;
}
