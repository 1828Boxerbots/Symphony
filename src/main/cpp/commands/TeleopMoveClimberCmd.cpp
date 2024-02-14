// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopMoveClimberCmd.h"

TeleopMoveClimberCmd::TeleopMoveClimberCmd(ClimberSub* pClimbSub, frc::XboxController* pController) 
{
  m_pController = m_pController;
  m_pClimbSub = pClimbSub;

  AddRequirements(pClimbSub);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TeleopMoveClimberCmd::Initialize() 
{
    
   m_IsFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void TeleopMoveClimberCmd::Execute() 
{
 
  if (m_pClimbSub == nullptr or m_pController == nullptr )
  {
    m_IsFinished = true;
    return;

  }

  bool leftbumber = m_pController->GetLeftBumper();

  if(leftbumber == true)
  {
    m_IsFinished = m_pClimbSub->Retract();
  }
  else
  {
    m_IsFinished = m_pClimbSub->Extend();
  }

}
  

// Called once the command ends or is interrupted.
void TeleopMoveClimberCmd::End(bool interrupted) 
{
  if (m_pClimbSub != nullptr)
  {
      m_pClimbSub->Stop();
   
  }
}

// Returns true when the command should end.
bool TeleopMoveClimberCmd::IsFinished() 
{

  return m_IsFinished;
}
