// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/VisionSub.h"
#include "subsystems/DriveSub.h"
#include "subsystems/ShooterSub.h"
#include "subsystems/LoaderSub.h"
#include "subsystems/ClimberSub.h"
#include "subsystems/BatonSub.h"
#include "subsystems/AutoSwitchSub.h"

#include "subsystems/LEDSub.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

  int GetDPDT();
  void Init();

  // Called by teleop init in order to make sure sensors are zeroed
  // for each subsystem that relies on sensors being zeroed.
  void ZeroSensors();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{OperatorConstants::kDriverControllerPort};
  frc2::CommandXboxController m_signalController{OperatorConstants::kSignalControllerPort};

  void ConfigureBindings();

  // The robot's subsystems are defined here...
  VisionSub m_visionSub;
  DriveSub m_driveSub;
  ShooterSub m_shooterSub;
  LoaderSub m_loaderSub;
  ClimberSub m_climberSub;
  BatonSub m_batonSub;
  AutoSwitchSub m_AutoSwitchSub;
  LEDSub m_LEDSub;
};
