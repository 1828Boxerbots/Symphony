// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSub.h"
#include "subsystems/LoaderSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoBackupAndLoadToPhotoGateCmd
    : public frc2::CommandHelper<frc2::Command, AutoBackupAndLoadToPhotoGateCmd> {
 public:
  AutoBackupAndLoadToPhotoGateCmd(DriveSub *pDrive, LoaderSub *pLoader, units::meter_t distance, double driveSpeed=1.0, double loaderSpeed=1.0);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    bool m_isFinished = false;

    DriveSub *m_pDrive = nullptr;
    LoaderSub *m_pLoader = nullptr;
    double m_driveSpeed = 1.0;
    double m_loaderSpeed = 1.0;
    frc::Timer m_timer;
    units::second_t m_startTime = 0.0_s;
    const units::second_t kTimeout = 2.0_s;

    units::meter_t m_distance = 0.0_m;
    units::meter_t m_startDistance = 0.0_m;
};
