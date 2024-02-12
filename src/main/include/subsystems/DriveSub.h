// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h> // from https://www.chiefdelphi.com/t/2024-software-download-links/448077.  use (https://software-metadata.revrobotics.com/REVLib-2024.json) file.
#include "Constants.h"
#include <frc/ADIS16448_IMU.h>


class DriveSub : public frc2::SubsystemBase 
{
 public:
  DriveSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

  void Init();
  void DriveTank(double left, double right);
  void DriveRC(double vertical, double horizontal);

  /// @brief gets yaw position (in degrees) from start position
  /// @return angle in degrees
  double GetAngle();
  double GetAngleX();
  double GetAngleY();
  double GetAngleZ();

  /// @brief gets the current distance traveled from left encoders
  /// @return distance in inches
  double GetDistanceL1();
  double GetDistanceL2();
  double GetSpeedL1();
  double GetSpeedL2();

  /// @brief gets the current distance traveled from right encoder2
  /// @return distance in inches
  double GetDistanceR1();
  double GetDistanceR2();
  double GetSpeedR1();
  double GetSpeedR2();


  void Periodic() override;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  private:
  ///////////////////////////////////////////////////////////////////////////////
  // CAN Motors
  rev::CANSparkMax m_motorL1 {OperatorConstants::kSymphonyDriveMotorIDL1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorR1 {OperatorConstants::kSymphonyDriveMotorIDR1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorL2 {OperatorConstants::kSymphonyDriveMotorIDL2, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_motorR2 {OperatorConstants::kSymphonyDriveMotorIDR2, rev::CANSparkMax::MotorType::kBrushless};

  // encoders are part of CANSparkMax - keep private
  inline rev::SparkRelativeEncoder GetEncoderL1()
  {
    return m_motorL1.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
  }
  inline rev::SparkRelativeEncoder GetEncoderL2()
  {
    return m_motorL2.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
  }
  inline rev::SparkRelativeEncoder GetEncoderR1()
  {
    return m_motorR1.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
  }
  inline rev::SparkRelativeEncoder GetEncoderR2()
  {
    return m_motorR2.GetEncoder(rev::CANEncoder::EncoderType::kHallSensor, OperatorConstants::NEO_ENCODER_COUNT);
  }

  ///////////////////////////////////////////////////////////////////////////////
  // IMU
  frc::ADIS16448_IMU m_imu;
};
