// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>

class ShooterSub : public frc2::SubsystemBase {
 public:
  ShooterSub();

  void Init();

  void Shoot(double speed);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 frc::PWMSparkMax m_motorR {2};
 frc::PWMSparkMax m_motorL {3};
 frc::Encoder m_encoderR {0, 1}; //placeholder port values
 frc::Encoder m_encoderL {2, 3}; //placeholder port values
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
