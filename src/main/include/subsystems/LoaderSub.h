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


  void Periodic() override;

 private:
 //frc::PWMSparkMax m_motor {OperatorConstants::kSymphonyLoaderMotor}; //placeholder port, not actually 5
 frc::DigitalInput m_photogate {OperatorConstants::kSymphonyLoaderPhotogate};

 //frc::Victor m_motor {OperatorConstants::kSymphonyLoaderMotor}; //used for testing with C418
 rev::CANSparkMax m_motor {OperatorConstants::kSymphonyLoaderMotor, rev::CANSparkMax::MotorType::kBrushed};


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
