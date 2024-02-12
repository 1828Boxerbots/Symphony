// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopShootCmd.h"
#include "frc/smartdashboard/SmartDashboard.h"

TeleopShootCmd::TeleopShootCmd(frc::XboxController *pController, ShooterSub *pSub) {
  AddRequirements(pSub);
  m_pController = pController;
  m_pSub = pSub;
}

// Called when the command is initially scheduled.
void TeleopShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleopShootCmd::Execute() 
{
  if ((m_pSub == nullptr) or (m_pController == nullptr))
  {
    m_isFinished = true; 
    return;
  }
  m_speed = m_pController->GetRightTriggerAxis();
  m_pSub->Shoot(m_speed);

}

// Called once the command ends or is interrupted.
void TeleopShootCmd::End(bool interrupted) 
{
  m_pSub->Shoot(0.0);
  
}

// Returns true when the command should end.
bool TeleopShootCmd::IsFinished() {
  return m_isFinished;
}
