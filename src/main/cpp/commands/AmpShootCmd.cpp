// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AmpShootCmd.h"

#include <utility>
#include <iostream>
#include <math.h>

AmpShootCmd::AmpShootCmd(double speed, ShooterSub *shooterSub, LoaderSub* loaderSub) 
{
  m_speed = speed;
  m_pShooterSub = shooterSub;
  m_pLoaderSub = loaderSub;

  AddRequirements(m_pLoaderSub);
  AddRequirements(m_pShooterSub);
}

// Called when the command is initially scheduled.
void AmpShootCmd::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AmpShootCmd::Execute() 
{
  if (m_pShooterSub == nullptr || m_pLoaderSub == nullptr)
  {
    m_isFinished = true;
  }
  
  m_pShooterSub->Shoot(-m_speed);

  // The first item is left motor, right is second
  std::pair<double, double> motorRPM = m_pShooterSub->GetMotorRPM();
  double loadFactor = 300;
  double targetRPM = OperatorConstants::NEO_MAX_RPM * m_speed - loadFactor;
  double avgRPM = ((fabs(motorRPM.first) + fabs(motorRPM.second)) / 2.0);

  std::cout << avgRPM << "/" << targetRPM << std::endl;

  if (avgRPM >= targetRPM)
    m_pLoaderSub->Load(0.25);
}

// Called once the command ends or is interrupted.
void AmpShootCmd::End(bool interrupted) \
{
  m_pShooterSub->Shoot(0.0);
  m_pLoaderSub->Load(0.0);
}

// Returns true when the command should end.
bool AmpShootCmd::IsFinished() {
  return m_isFinished;
}
