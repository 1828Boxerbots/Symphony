// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/BatonSub.h"
#include <frc/XboxController.h>
#include "subsystems/ClimberSub.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SafeTeleopMoveClimberCmd
    : public frc2::CommandHelper<frc2::Command, SafeTeleopMoveClimberCmd> {
 public:
  SafeTeleopMoveClimberCmd(frc::XboxController *pController, BatonSub *pSub, ClimberSub *pClimbSub);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  frc::XboxController *m_pController = nullptr;
  BatonSub *m_pBatonSub = nullptr; 
  bool m_isFinished = false;
  ClimberSub *m_pClimbSub = nullptr;
};
