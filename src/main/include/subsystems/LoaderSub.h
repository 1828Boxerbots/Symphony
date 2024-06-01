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
#include <frc/AnalogInput.h>

class LoaderSub : public frc2::SubsystemBase 
{
 public:
  LoaderSub();

  void Init();
  
  void Periodic() override;

  /// @brief Sets the speed of the loader motor.
  /// @param speed The speed to move at.
  void Load(double speed);

  /// @brief Retrieves the status of the photogate.
  /// @return True if the photogate is not tripped, false when tripped.
  static bool GetPhotoGate();

  /// @brief Retrieves the status of the temperature safety.
  /// @return True if the safety is engaged.
  static bool GetSafetyEngaged();

  /// @brief Gets the current speed of the loader motor.
  /// @return The current RPM of the motor.
  double GetEncoderSpeed();

  /// @brief Calculates the distance reading of the ultrasonic in inches
  /// @return The distance in inches.
  static double GetUltrasonicDistance();

 private:
  // DIO
  static frc::DigitalInput m_photogate;
  static bool m_SafetyEngaged;

  // Analog
  static frc::AnalogInput m_ultrasonic;

  // Motor Controllers
  rev::CANSparkMax m_motor {OperatorConstants::kSymphonyLoaderMotorID, rev::CANSparkMax::MotorType::kBrushless};
};
