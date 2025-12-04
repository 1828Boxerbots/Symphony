// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LoadCmd.h"
#include <frc/smartdashboard/SmartDashboard.h>

LoadCmd::LoadCmd(frc::XboxController *pController, LoaderSub *pSub, double speed) 
{
  AddRequirements(pSub);
  m_pController = pController;
  m_pSub = pSub;
  m_speed = -speed; 
}

// Called when the command is initially scheduled.
void LoadCmd::Initialize() 
{
  
}

// Called repeatedly when this Command is scheduled to run
void LoadCmd::Execute() 
{
  if ((m_pSub == nullptr) or (m_pController == nullptr))
  {
    m_isFinished = true; 
    return;
  }

  double speed = m_speed;


  if (m_pController->GetLeftBumper() == true)
  {
    speed = -speed;
  }
  m_pSub->Load(speed);
  frc::SmartDashboard::PutNumber("Loader Speed", speed);
}

// Called once the command ends or is interrupted.
void LoadCmd::End(bool interrupted) 
{
  m_pSub->Load(0.0);
}

// Returns true when the command should end.
bool LoadCmd::IsFinished() {
  return m_isFinished;
}
