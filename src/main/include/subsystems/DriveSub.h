// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
//#include <rev/CANSparkMax.h>
#include <frc/Encoder.h>
#include "Constants.h"



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


  void Periodic() override;

 private:
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlL1 {OperatorConstants::kSymphonyDriveMotorControlL1};
 // rev::CANSparkMax m_motorL1 {kSymphonyDriveMotorIDL1, rev::CANSparkMax::MotorType::kBrushed};

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlR1 {OperatorConstants::kSymphonyDriveMotorControlR1};
  //rev::CANSparkMax m_motorR1 {kSymphonyDriveMotorIDR1, rev::CANSparkMax::MotorType::kBrushed};

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlL2 {OperatorConstants::kSymphonyDriveMotorControlL2};
  //rev::CANSparkMax m_motorL2 {kSymphonyDriveMotorIDL2, rev::CANSparkMax::MotorType::kBrushed};

  ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorControlR2 {OperatorConstants::kSymphonyDriveMotorControlR2};
  //rev::CANSparkMax m_motorR2 {kSymphonyDriveMotorIDR2, rev::CANSparkMax::MotorType::kBrushed};


  frc::Encoder m_encoderL{OperatorConstants::kSymphonyDriveEncoderAL, OperatorConstants::kSymphonyDriveEncoderBL};
  frc::Encoder m_encoderR{OperatorConstants::kSymphonyDriveEncoderAR, OperatorConstants::kSymphonyDriveEncoderBR};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
