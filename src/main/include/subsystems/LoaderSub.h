// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/Victor.h>
#include <frc/DigitalInput.h>
#include <Constants.h>
#include <rev/CANSparkMax.h>

class LoaderSub : public frc2::SubsystemBase {
 public:
  LoaderSub();

  void Init();
  void Load(double speed);
  bool GetPhotoGate();

  double GetEncoderSpeed();

  void Periodic() override;

 private:
  // DIO
  frc::DigitalInput m_photogate {OperatorConstants::kSymphonyLoaderPhotogate};

  // Motor Controllers
  rev::CANSparkMax m_motor {OperatorConstants::kSymphonyLoaderMotorID, rev::CANSparkMax::MotorType::kBrushless};
};
