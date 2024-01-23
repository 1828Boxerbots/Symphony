// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ShooterSub.h"
#include <frc/XboxController.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TeleopShootCmd
    : public frc2::CommandHelper<frc2::Command, TeleopShootCmd> {
 public:
  TeleopShootCmd(frc::XboxController *pController, ShooterSub *pSub);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private: 
  frc::XboxController *m_pController = nullptr;
  ShooterSub *m_pSub = nullptr;
  bool m_isFinished = false;
  double m_speed = 0;
};
