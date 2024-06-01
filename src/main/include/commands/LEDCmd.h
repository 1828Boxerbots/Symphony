// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/LEDSub.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LEDCmd
    : public frc2::CommandHelper<frc2::Command, LEDCmd> {
 public:
  LEDCmd(LEDSub *pSub, frc::XboxController* pController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private: 
  LEDSub *m_pSub = nullptr;
  frc::XboxController* m_pController = nullptr;

  unsigned int m_flashCounts = 15;
  unsigned int m_CurrentFlashCount = 0;
  bool m_FlashOn = false;
  AllianceColor m_allianceColor;
  frc::Timer m_Timer;

  bool m_toggleTopSignal = false;
  bool m_toggleDriverSignal = false;
  
  bool m_isFinished = false;
};
