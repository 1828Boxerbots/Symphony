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

  void DriveDistancePID(double distance);
  void SetPIDSpeed(double speed);
  double GetAvgDistance();

  void ZeroSensors();

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

  rev::SparkMaxRelativeEncoder m_leftEncoder1 = m_motorL1.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkMaxRelativeEncoder m_leftEncoder2 = m_motorL2.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkMaxRelativeEncoder m_rightEncoder1 = m_motorR1.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
  rev::SparkMaxRelativeEncoder m_rightEncoder2 = m_motorR2.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);

  rev::SparkPIDController m_leftPID1 = m_motorL1.GetPIDController();
  rev::SparkPIDController m_leftPID2 = m_motorL2.GetPIDController();
  rev::SparkPIDController m_rightPID1 = m_motorR1.GetPIDController();
  rev::SparkPIDController m_rightPID2 = m_motorR2.GetPIDController();

  double m_kP= 0.08;
  double m_kI = 0;
  double m_kD = 1;
  double m_kIZ = 0;
  double m_kF = 0;

  ///////////////////////////////////////////////////////////////////////////////
  // IMU
  //frc::ADIS16448_IMU m_imu;
};
