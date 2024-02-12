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
#include <math.h>

class ShooterSub : public frc2::SubsystemBase {
 public:
  ShooterSub();

  void Init();

  void Shoot(double speed);

  void Periodic() override; 

  double CalculateSpeed(double distanceToTarget); 

  double GetSpeed();

 private:
 double m_pulses = 363; //placeholder value, real number of pulses not yet known

rev::CANSparkMax m_motorL {OperatorConstants::kSymphonyShooterPWMPortL, rev::CANSparkMax::MotorType::kBrushed};
rev::CANSparkMax m_motorR {OperatorConstants::kSymphonyShooterPWMPortR, rev::CANSparkMax::MotorType::kBrushed};

};
