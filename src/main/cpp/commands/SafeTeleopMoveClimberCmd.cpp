// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SafeTeleopMoveClimberCmd.h"
#include <Constants.h>

SafeTeleopMoveClimberCmd::SafeTeleopMoveClimberCmd(frc::XboxController *pController, BatonSub *pBatonSub, ClimberSub *pClimbSub) 
{
  AddRequirements(pBatonSub);
  AddRequirements(pClimbSub);
  m_pController = pController;
  m_pBatonSub = pBatonSub;
  m_pClimbSub = pClimbSub;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SafeTeleopMoveClimberCmd::Initialize() 
{

}

// Called repeatedly when this Command is scheduled to run
void SafeTeleopMoveClimberCmd::Execute() 
{
  if ((m_pBatonSub == nullptr) or (m_pController == nullptr) or (m_pClimbSub == nullptr))
  {
    m_isFinished = true; 
    return;
  }

  // Check if Baton is at Rest 
  if (m_pBatonSub->IsAtRestLimit() == true)
  {
    //Check if bumper is pressed
    if (m_pController->GetLeftBumper() == true)
    {
      //if pressed retract
      m_pClimbSub->Retract();
    }
    else
    {
      //if not pressed extend
      m_pClimbSub->Extend();
    }
  }
  else
  {
    //set baton to rest if its not at rest while attempting to use climber
    m_pBatonSub->GoToRest();
  }
  
}

// Called once the command ends or is interrupted.
void SafeTeleopMoveClimberCmd::End(bool interrupted) 
{
   if ((m_pBatonSub != nullptr) and (m_pClimbSub != nullptr))
  {
    m_pBatonSub->Stop();
    m_pClimbSub->Stop();
  }
}

// Returns true when the command should end.
bool SafeTeleopMoveClimberCmd::IsFinished() 
{
  return m_isFinished;
}
