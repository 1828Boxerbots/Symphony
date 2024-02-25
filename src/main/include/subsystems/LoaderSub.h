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
  
  void Periodic() override;

  /// @brief Sets the speed of the loader motor.
  /// @param speed The speed to move at.
  void Load(double speed);

  /// @brief Retrieves the status of the photogate.
  /// @return True if the photogate is not tripped, false when tripped.
  bool GetPhotoGate();

  /// @brief Gets the current speed of the loader motor.
  /// @return The current RPM of the motor.
  double GetEncoderSpeed();


 private:
  // DIO
  frc::DigitalInput m_photogate {OperatorConstants::kSymphonyLoaderPhotogate};

  // Motor Controllers
  rev::CANSparkMax m_motor {OperatorConstants::kSymphonyLoaderMotorID, rev::CANSparkMax::MotorType::kBrushless};
};
