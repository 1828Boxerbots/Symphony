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
  void SetPosition(double pos);
  void SetMotors(double speed);

  inline bool GetUpperHallTripped() const { return m_UpperHallEffect.Get(); }
  inline double GetEncoderPos() const { return m_EncoderL.GetPosition(); }

  void ZeroSensors();

 private:
  

  rev::CANSparkMax m_motorL{OperatorConstants::kSymphonyBatonMotorIDL, rev::CANSparkMax::MotorType::kBrushless}; 
  rev::CANSparkMax m_motorR{OperatorConstants::kSymphonyBatonMotorIDR, rev::CANSparkMax::MotorType::kBrushless}; 

  rev::SparkRelativeEncoder m_EncoderL = m_motorL.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkRelativeEncoder m_EncoderR = m_motorR.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::SparkPIDController m_PIDLeft = m_motorL.GetPIDController();
  rev::SparkPIDController m_PIDRight = m_motorR.GetPIDController();

  frc::DigitalInput m_UpperHallEffect {OperatorConstants::kBatonUpperHallEffect};

  // PID coefficients
  double m_kP= 0.08;
  double m_kI = 0;
  double m_kD = 1;
  double m_kIZ = 0;
  double m_kF = 0;
  double m_kMaxOutput = 0.15;
  double m_kMinOutput = -0.2;
};

