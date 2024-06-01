// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoBackupAndLoadToPhotoGateCmd.h"

AutoBackupAndLoadToPhotoGateCmd::AutoBackupAndLoadToPhotoGateCmd(DriveSub *pDrive, LoaderSub *pLoader, units::meter_t distance, double driveSpeed, double loaderSpeed) 
{
  m_pDrive = pDrive;
  m_pLoader = pLoader;
  m_distance = distance;
  m_driveSpeed = fabsf(driveSpeed);
  m_loaderSpeed = fabsf(loaderSpeed);

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDrive);
  AddRequirements(pLoader);
}

// Called when the command is initially scheduled.
void AutoBackupAndLoadToPhotoGateCmd::Initialize() 
{
  if (m_pDrive == nullptr or m_pLoader == nullptr)
  {
    m_isFinished = true;
    return;
  }
  m_startDistance = (units::inch_t)m_pDrive->GetDistanceL1();

  m_timer.Reset();
  m_timer.Start();
  m_startTime = m_timer.Get();
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoBackupAndLoadToPhotoGateCmd::Execute() 
{
  if (m_pDrive == nullptr or m_pLoader == nullptr or m_isFinished == true)
  {
    m_isFinished = true;
    return;
  }

  // backup
  m_pDrive->DriveTank(-m_driveSpeed, -m_driveSpeed);
  m_pLoader->Load(m_loaderSpeed);

  // if note is at photogate
  if (m_pLoader->GetPhotoGate() == true)
  {
    m_isFinished = true;
    return;
  }
  // check if we passed distance estimated
  if ((units::meter_t)(units::inch_t)m_pDrive->GetDistanceL1() - m_startDistance >= m_distance)
  {
    m_isFinished = true;
    return;
  }

  // check if we missed/passed the note
  if (m_timer.Get() - m_startTime > kTimeout)
  {
    m_isFinished = true;
    return;
  }
}

// Called once the command ends or is interrupted.
void AutoBackupAndLoadToPhotoGateCmd::End(bool interrupted) 
{
  if (m_pLoader != nullptr and m_pDrive != nullptr)
  {
    // stop loader and drive
    m_pLoader->Load(0.0);
    m_pDrive->DriveTank(0.0, 0.0);
  }
}

// Returns true when the command should end.
bool AutoBackupAndLoadToPhotoGateCmd::IsFinished() 
{
  return m_isFinished;
}
