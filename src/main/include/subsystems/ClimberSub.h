// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "../Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/DigitalInput.h>




class ClimberSub : public frc2::SubsystemBase {
 public:
  ClimberSub();

  void Init();
  void SetMotors(double speed);
  bool Extend(); //same as go to swing for baton sub
  bool Retract(); // same as go to rest for baton sub
  void Stop(); 
  bool IsAtRetractLimit();
  bool IsAtExtendLimit();
  bool IsAtClimbSensor();
  

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

 bool m_isClimbable = false; //Suposed to me made true when Climb arm gets fully extended 

frc::DigitalInput m_retractMagnet{OperatorConstants::kSymphonyClimberExtendMagnetPort};
frc::DigitalInput m_extendMagnet{OperatorConstants::kSymphonyClimberRetractMagnetPort};
frc::DigitalInput m_climbingMagnet{OperatorConstants::kSymphonyClimberClimbingMagnetPort};

ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorL{OperatorConstants::kSymphonyClimberMotorLeft};
ctre::phoenix::motorcontrol::can::WPI_VictorSPX m_motorR{OperatorConstants::kSymphonyClimberMotorRight};


 //cmds

 //ExtendCmd m_ExtendCmd;



  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
