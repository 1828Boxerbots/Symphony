// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PickupNoteCmd.h"
#include <frc/smartdashboard/SmartDashboard.h>

PickupNoteCmd::PickupNoteCmd(LoaderSub *pSub, frc::XboxController* controller, double speed) 
{
  AddRequirements(pSub);
  m_pSub = pSub;
  m_pController = controller;
  m_speed = speed; 
}

// Called when the command is initially scheduled.
void PickupNoteCmd::Initialize() 
{
  
}

// Called repeatedly when this Command is scheduled to run
void PickupNoteCmd::Execute() 
{
  if (m_pSub == nullptr || m_pController == nullptr)
  {
    m_isFinished = true; 
    return;
  }

  double speed = m_speed;
  if (m_pController->GetLeftBumper())
    speed = -speed;

  m_pSub->Load(speed);
}

// Called once the command ends or is interrupted.
void PickupNoteCmd::End(bool interrupted) 
{
  m_pSub->Load(0.0);
}

// Returns true when the command should end.
bool PickupNoteCmd::IsFinished() {
  return m_isFinished;
}
