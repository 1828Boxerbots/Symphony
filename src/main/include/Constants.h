// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants 
{
inline constexpr int kDriverControllerPort = 0;

//Drive:
inline constexpr int kSymphonyDriveMotorIDR1 = 1;
inline constexpr int kSymphonyDriveMotorIDR2 = 2;
inline constexpr int kSymphonyDriveMotorIDL1 = 3;
inline constexpr int kSymphonyDriveMotorIDL2 = 4;

//Shooter:
inline constexpr int kSymphonyShooterIDL = 5;
inline constexpr int kSymphonyShooterIDR = 6;

//Loader:
inline constexpr int kSymphonyLoaderPhotogate = 7;
inline constexpr int kSymphonyLoaderMotorID = 7;

//Baton:
inline constexpr int kSymphonyBatonMotorIDL = 8;
inline constexpr int kSymphonyBatonMotorIDR = 9; 
inline constexpr int kBatonUpperHallEffect = 0;

// Climber
inline constexpr int kSymphonyClimberMotorIDL = 10; 
inline constexpr int kSymphonyClimberMotorIDR = 11;  
inline constexpr double kSymphonyClimberMotorSpeed = 0.1; 

// Autonomous Selector
inline constexpr int kSymphonyAutoSwithPort1 = 1;   // TODO: Figure out the real port value
inline constexpr int kSymphonyAutoSwithPort2 = 2;   // TODO: Figure out the real port value

// Constants
inline constexpr int NEO_ENCODER_COUNT = 42;
inline constexpr double PI = 3.14159;
inline constexpr double NEO_MAX_OPENLOAD_RPM = 5676;    // The max RPM of NEO motor without any load
inline constexpr double NEO_LOAD_FACTOR = 0.05;         // Estimated from calculated load factors

}  // namespace OperatorConstants
