// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Commands/AutoForwardCmd.h"

AutoForwardCmd::AutoForwardCmd(DriveSub *pDrive, units::meter_t distanceInMeters, double speed) 
{
  m_pDrive = pDrive;
  m_distanceInMeters = (units::meter_t)fabsf((double)distanceInMeters); // distance always positive
  m_speed = speed;

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDrive);
}

// Called when the command is initially scheduled.
void AutoForwardCmd::Initialize() 
{
  if (m_pDrive == nullptr)
  {
    m_isFinished = true;
    return;
  }

  m_startDistance = (units::meter_t)m_pDrive->GetDistanceL1();
  //m_startDistance = (units::meter_t)m_pDrive->GetDistanceL2();
  //m_startDistance = (units::meter_t)m_pDrive->GetDistanceR1();
  //m_startDistance = (units::meter_t)m_pDrive->GetDistanceR2();
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoForwardCmd::Execute() 
{
  if (m_pDrive == nullptr or m_distanceInMeters == 0.0_m)
  {
    m_isFinished = true;
    return;
  }

  m_pDrive->DriveTank(m_speed, m_speed);
  if (m_speed > 0.0)
  {
    m_isFinished = ((units::meter_t)m_pDrive->GetDistanceL1() - m_startDistance > m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceL2() - m_startDistance > m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceR1() - m_startDistance > m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceR2() - m_startDistance > m_distanceInMeters);
  }
  else
  {
    m_isFinished = ((units::meter_t)m_pDrive->GetDistanceL1() - m_startDistance < -m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceL2() - m_startDistance < -m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceR1() - m_startDistance < -m_distanceInMeters);
    // m_isFinished = ((units::meter_t)m_pDrive->GetDistanceR2() - m_startDistance < -m_distanceInMeters);
  }
}

// Called once the command ends or is interrupted.
void AutoForwardCmd::End(bool interrupted) 
{
  if (m_pDrive != nullptr)
  {
    // stop the motors
    m_pDrive->DriveTank(0.0, 0.0);
  }
}

// Returns true when the command should end.
bool AutoForwardCmd::IsFinished() 
{
  return m_isFinished;
}
