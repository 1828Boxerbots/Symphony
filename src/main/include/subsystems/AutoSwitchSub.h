// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <rev/CANSparkMax.h>
#include <frc/DigitalInput.h>

#include <utility>

enum class AutonomousMode
{
    POS1,
    POS2,
    POS3
};

class AutoSwitchSub : public frc2::SubsystemBase {
 public:
  AutoSwitchSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override; 

  void Init();

  AutonomousMode GetSelectedMode();

 private:

  frc::DigitalInput m_SwitchHigh {OperatorConstants::kSymphonyAutoSwithPort1};
  frc::DigitalInput m_SwitchLow {OperatorConstants::kSymphonyAutoSwithPort2};

  // PID coefficients
};

