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
inline constexpr int kSignalControllerPort = 1;

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
inline constexpr int kSymphonyLoaderUltrasonic = 0;
inline constexpr int kSymphonyLoaderMotorID = 7;
inline constexpr double ULTRASONIC_LOADED_DIST = 12.0;   // Represents 2 inches

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

// LEDs
inline constexpr int kLEDPort = 0;
inline constexpr int PIXEL_COUNT = 119;

// Constants
inline constexpr int NEO_ENCODER_COUNT = 42;
inline constexpr double ToInches = 0.393701;
inline constexpr double ToCM = 2.53;
inline constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
inline constexpr double NEO_MAX_OPENLOAD_RPM = 5676;    // The max RPM of NEO motor without any load
inline constexpr double NEO_LOAD_FACTOR = 0.05;         // Estimated from calculated load factors
inline constexpr double MOTOR_CUTOFF_TEMP = 50.0;   // Degrees Celsius

// Vision:
inline constexpr int kMaxTargetId = 16;

//Useful Constants
constexpr double ToInches = 0.393701;
constexpr double ToCM = 2.53;
constexpr double PI = 3.141592653589793238462643383279502884197169399375105820974944;
constexpr double MetersPerInch = 0.0254;


}  // namespace OperatorConstants
