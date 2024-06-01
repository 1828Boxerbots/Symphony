// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ShooterSub.h"
#include "subsystems/VisionSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoVisionShootCmd
    : public frc2::CommandHelper<frc2::Command, AutoVisionShootCmd> {
 public:
  AutoVisionShootCmd(ShooterSub *pDrive, VisionSub *pVision);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    bool m_isFinished = false;

    ShooterSub *m_pShooter = nullptr;
    VisionSub *m_pVision = nullptr;

    double m_rangeToTarget = 0.0;
    double m_speed = 0.0;
};
