// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <rev/CANSparkMax.h> // from https://www.chiefdelphi.com/t/2024-software-download-links/448077.  use (https://software-metadata.revrobotics.com/REVLib-2024.json) file.
#include "Constants.h"
#include <frc/ADIS16470_IMU.h>

class DriveSub : public frc2::SubsystemBase 
{
 public:
  DriveSub();

  void Init();

  void Periodic() override;

  /// @brief Called to set the motors to each of their required speeds.
  /// @param left The speed of the left motors.
  /// @param right The speed of the right motors.
  void DriveTank(double left, double right);

  /// @brief Takes in vertical and horizontal input values and translates them to motor values.
  /// @param vertical The vertical component of the speed.
  /// @param horizontal The horizontal component of the speed.
  void DriveRC(double vertical, double horizontal);

  /// @brief Moves the robot using a PID to reach a specified distance.
  /// @param distance The distance to move to.
  void DriveDistancePID(double distance);

  /// @brief Sets the max and min speed of the PID controller.
  /// @param speed The speed to set the PID to.
  void SetPIDSpeed(double speed);

  /// @brief Calculates the avg distance travelled between all four drive encoders.
  /// @return The average encoder distance.
  double GetAvgDistance();

  /// @brief Called to zero sensitive sensors.
  void ZeroSensors();

  /// @brief Resets the IMU so that whatever direction it is facing
  ///        is considered forward (0 degrees)
  void ResetIMU();

  /// @brief Retrieves the current yaw of the IMU
  /// @return The yaw in degrees (CCW is positive)
  double GetYaw();

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

  double m_kP= 0.035;
  double m_kI = 0;
  double m_kD = 1;
  double m_kIZ = 0;
  double m_kF = 0;

  frc::ADIS16470_IMU m_imu;
};
