// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopShootCmd.h"
#include "Util.h"

TeleopShootCmd::TeleopShootCmd(frc::XboxController *pController, ShooterSub *pShooterSub, VisionSub *pVisionSub) 
{
  AddRequirements(pShooterSub);
  AddRequirements(pVisionSub);
  m_pController = pController;
  m_pShooterSub = pShooterSub;
  m_pVisionSub = pVisionSub;

  SetName("TeleopShootCmd");
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

  double speed = 0.0;
  bool bumperPressed = m_pController->GetLeftBumper();

  if (bumperPressed == true)
  {
    speed = m_pController->GetRightTriggerAxis();
  }
  else
  {
      speed = m_pShooterSub->CalculateSpeed((double)m_pVisionSub->GetDistanceInInches() * OperatorConstants::MetersPerInch); //Remove parameter to get distance, there should not be a parameter
  }
  m_pShooterSub->Shoot(speed);

  Util::Log("Speed", speed, GetName());
  Util::Log("LeftBumper pressed", bumperPressed, GetName());
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
