// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoTurnCmd
    : public frc2::CommandHelper<frc2::Command, AutoTurnCmd> {
 public:
  AutoTurnCmd(DriveSub *pDrive, double absoluteAngle, double speed = 0.5);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    DriveSub *m_pDrive = nullptr;
    double m_absoluteAngle = 0.0;
    double m_speed = 0.0;

    bool m_isFinished = false;
};
