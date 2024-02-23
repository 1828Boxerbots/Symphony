// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <rev/CANSparkMax.h>
#include <frc/DigitalInput.h>

class BatonSub : public frc2::SubsystemBase {
 public:
  BatonSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override; 

  void Init();

  void Stop();
  
  void MoveToExtended(double speed);
  void MoveToStowed(double speed);

  inline bool GetUpperHallTripped() const { return m_UpperHallEffect.Get(); }
  inline double GetEncoderPos() const { return m_EncoderL.GetPosition(); }

  void ZeroSensors();

 private:
  
  void SetMotor(double speed);

  rev::CANSparkMax m_motorL{OperatorConstants::kSymphonyBatonMotorIDL, rev::CANSparkMax::MotorType::kBrushless}; 
  rev::CANSparkMax m_motorR{OperatorConstants::kSymphonyBatonMotorIDR, rev::CANSparkMax::MotorType::kBrushless}; 

  rev::SparkRelativeEncoder m_EncoderL = m_motorL.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkPIDController m_PIDLeft = m_motorL.GetPIDController();

  frc::DigitalInput m_UpperHallEffect {OperatorConstants::kBatonUpperHallEffect};

  // PID coefficients
  double m_kP= 0.1;
  double m_kI = 1e-4;
  double m_kD = 1;
  double m_kIZ = 0;
  double m_kF = 0;
  double m_kMaxOutput = 1.0;
  double m_kMinOutput = -1.0;
};

