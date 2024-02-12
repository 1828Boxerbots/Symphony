// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopShootCmd.h"
#include "frc/smartdashboard/SmartDashboard.h"

TeleopShootCmd::TeleopShootCmd(frc::XboxController *pController, ShooterSub *pShooterSub, VisionSub *pVisionSub) {
  AddRequirements(pShooterSub);
  AddRequirements(pVisionSub);
  m_pController = pController;
  m_pShooterSub = pShooterSub;
  m_pVisionSub = pVisionSub;
}

// Called when the command is initially scheduled.
void TeleopShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleopShootCmd::Execute() 
{
  if ((m_pShooterSub == nullptr) or (m_pController == nullptr) or (m_pVisionSub == nullptr))
  {
    m_isFinished = true; 
    return;
  }

  double speed = m_pShooterSub->CalculateSpeed((double)m_pVisionSub->GetDistanceInMeters()); //Remove parameter to get distance, there should not be a parameter

  if (m_pController->GetLeftBumper() == true)
  {
    speed = m_pController->GetRightTriggerAxis();
  }
  m_pShooterSub->Shoot(speed);
  frc::SmartDashboard::PutNumber("Speed", speed);
  frc::SmartDashboard::PutBoolean("LeftBumper Pressed", m_pController->GetLeftBumper());

}

// Called once the command ends or is interrupted.
void TeleopShootCmd::End(bool interrupted) 
{
  m_pShooterSub->Shoot(0.0);
  
}

// Returns true when the command should end.
bool TeleopShootCmd::IsFinished() {
  return m_isFinished;
}
