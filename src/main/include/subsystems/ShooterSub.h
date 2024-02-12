// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>
#include <frc/motorcontrol/Victor.h>
#include <Constants.h>
#include <rev/CANSparkMax.h>

class ShooterSub : public frc2::SubsystemBase {
 public:
  ShooterSub();

  void Init();

  void Shoot(double speed);

  void Periodic() override;

  double GetSpeedL();
  double GetSpeedR();

 private:

rev::CANSparkMax m_motorL {OperatorConstants::kSymphonyShooterIDL, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax m_motorR {OperatorConstants::kSymphonyShooterIDR, rev::CANSparkMax::MotorType::kBrushless};  

inline rev::SparkRelativeEncoder GetEncoderL()
{
  return m_motorL.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
}

inline rev::SparkRelativeEncoder GetEncoderR()
{
  return m_motorR.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
}
};
