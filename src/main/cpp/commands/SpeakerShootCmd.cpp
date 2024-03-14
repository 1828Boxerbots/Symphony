// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SpeakerShootCmd.h"
#include <frc/DriverStation.h>

#include "frc/smartdashboard/SmartDashboard.h"

SpeakerShootCmd::SpeakerShootCmd(frc::XboxController *pController, ShooterSub *shooterSub, LoaderSub* loaderSub, VisionSub* visionSub) {
  m_pController = pController;
  m_pShooterSub = shooterSub;
  m_pLoaderSub = loaderSub;
  m_pVisionSub = visionSub;

  AddRequirements(m_pShooterSub);
  AddRequirements(m_pLoaderSub);
  AddRequirements(m_pVisionSub);
}

// Called when the command is initially scheduled.
void SpeakerShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpeakerShootCmd::Execute() 
{
  if ((m_pShooterSub == nullptr) or (m_pController == nullptr) || m_pLoaderSub == nullptr || m_pVisionSub == nullptr)
  {
    m_isFinished = true; 
    return;
  }
  m_speed = m_pController->GetRightTriggerAxis();
  m_pShooterSub->Shoot(-m_speed);

  double targetSpeed;
  auto allianceColor = frc::DriverStation::GetAlliance().value();
  if (allianceColor == frc::DriverStation::Alliance::kRed)
  {
    targetSpeed = m_pShooterSub->CalculateSpeed(2.0 * (double)m_pVisionSub->GetDistanceInMeters(4));
  }
  else
  {
    targetSpeed = m_pShooterSub->CalculateSpeed(2.0 * (double)m_pVisionSub->GetDistanceInMeters(7));
  }

  double targetRPM = OperatorConstants::NEO_MAX_OPENLOAD_RPM * targetSpeed; // Calculates the target RPM with no load
  double loadFactor = targetRPM * OperatorConstants::NEO_LOAD_FACTOR;       // Calculates the affect of load on the motors
  targetRPM -= loadFactor;                                                  // Applies the load factor to give target RPM with load factor

  // The first item is left motor, right is second
  std::pair<double, double> motorRPM = m_pShooterSub->GetMotorRPM();
  double avgRPM = ((fabs(motorRPM.first) + fabs(motorRPM.second)) / 2.0);

  if (avgRPM >= targetRPM)
    m_pLoaderSub->Load(0.7);
}

// Called once the command ends or is interrupted.
void SpeakerShootCmd::End(bool interrupted) 
{
  m_pShooterSub->Shoot(0.0);
  m_pLoaderSub->Load(0.0);
}

// Returns true when the command should end.
bool SpeakerShootCmd::IsFinished() {
  return m_isFinished;
}
