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
inline constexpr int kSymphonyDriveMotorIDR1 = 0;
inline constexpr int kSymphonyDriveMotorIDR2 = 1;
inline constexpr int kSymphonyDriveMotorIDL1 = 2;
inline constexpr int kSymphonyDriveMotorIDL2 = 3;

//Shooter:
inline constexpr int kSymphonyShooterIDL = 4;
inline constexpr int kSymphonyShooterIDR = 5;

//Loader:
inline constexpr int kSymphonyLoaderPhotogate = 0;
inline constexpr int kSymphonyLoaderMotorID = 5;

//Baton:
inline constexpr int kSymphonyBatonMotorIDL = 7; //bogus port value, not true at all
inline constexpr int kSymphonyBatonMotorIDR = 8; //bogus port value, not true at all 
inline constexpr int kSymphonyBatonOptimalSpeed = 0.1; //unknown true optimal speed as of now 

// Climber
inline constexpr int kSymphonyClimberMotorIDL = 9; 
inline constexpr int kSymphonyClimberMotorIDR = 10;  
inline constexpr double kSymphonyClimberMotorSpeed = 0.1; 

// Constants
inline constexpr int NEO_ENCODER_COUNT = 42;
inline constexpr double PI = 3.14159;

}  // namespace OperatorConstants
