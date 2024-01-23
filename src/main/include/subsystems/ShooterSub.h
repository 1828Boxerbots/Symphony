// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>
#include <frc/motorcontrol/Victor.h>

class ShooterSub : public frc2::SubsystemBase {
 public:
  ShooterSub();

  void Init();

  void Shoot(double speed);

  void Periodic() override;

  void SetMotors(double speed);

 private:
 double m_pulses = 363; //placeholder value, real number of pulses not yet known
 //frc::PWMSparkMax m_motorR {2};
 //frc::PWMSparkMax m_motorL {3};
frc::Victor m_motorR {2}; //for testing on C418, uncomment PWMSparkMaxes for real testing
frc::Victor m_motorL {3}; //for testing on C418, uncomment PWMSparkMaxes for real testing


 frc::Encoder m_encoderR {0, 1}; //placeholder port values
 frc::Encoder m_encoderL {2, 3}; //placeholder port values


  
};
