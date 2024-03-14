/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/Timer.h>
#include <wpi/SmallString.h>

#include "hal/DriverStation.h"

namespace Util
{
    /// @brief Clamps the input between the provided limits.
    /// @param value The value to clamp.
    /// @param lowerLimit The lower bound of the range to clamp to.
    /// @param higherLimit The upper bound of the range to clamp to.
    /// @return The value either clamped to be witing range, or the original
    ///         if already in range.
    double Limit(double value, double lowerLimit = -1.0, double higherLimit = 1.0);

    /// @brief Finds the mimimum absolute value.
    /// @param input The value to compare.
    /// @param minValue The minimum value to report.
    /// @return The original value or the mimimum allowed value.
    double AbsMin(double input, double minValue);

    /// @brief Finds the maximum absolute value.
    /// @param input The value to compare.
    /// @param maxValue The maximum value to report.
    /// @return The original value or the maximum allowed value.
    double AbsMax(double input, double maxValue);

    /// @brief Finds the absolute value.
    /// @param input The value to convert to absolute value.
    /// @return The original input without the sign if it had one.
    double Abs(double input);
    
    /// @brief Delays execution of the current thread for the number of seconds
    ///         specified.
    /// @param seconds The number of seconds to wait for.
    void DelayInSeconds(units::second_t seconds);
    
    /// @brief Formats a string that represents a timestamp in YYYY-MM-DD-HH-mm.
    /// @return The formatted string.
    std::string TimeStampStr();
    
    /// @brief Compares the value of doubles using the specified tolerances.
    /// @param value The value to be verified that is is considered the desired number.
    /// @param requiredValue The desired value that the input should be equal to.
    /// @param tolerance The accuraccy that a number must be within to be equal.
    /// @return True if the number is equal within tolerance. False otherwise.
    bool CompareDouble(double value, double requiredValue, double tolerance = 0.001);
    
    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, double value, std::string subsystemName = "");

    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, int value, std::string subsystemName = "");

    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, unsigned int value, std::string subsystemName = "");

    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, bool value, std::string subsystemName = "");

    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, std::string value, std::string subsystemName = "");

    /// @brief Logs the value to the smartdashboard.
    /// @param title The title to apply to the logged value.
    /// @param value The value to log.
    /// @param subsystemName The name of the subsystem it belongs to.
    void Log(std::string title, const char *value, std::string subsystemName = "");
    
    /// @brief Used to calculate the distance per pulse for encoders attached to wheels. Used to
    ///         convert the rotations of an encoder to linear distance.
    /// @param wheelDiameter The diameter of the wheels attached to system.
    /// @param revPerPulse The number of revolutions per pulse.
    /// @param gearRatio The gear ratio of the system.
    /// @return 
    double CalculateDistPerPulse(const double wheelDiameter, const int revPerPulse, const double gearRatio = 1.0);

    /// @brief Given an angle in degrees, it will convert the angle to radians.
    /// @param degrees The angle to convert in degrees.
    /// @return The angle in radians.
    double ConvertToRadians(double degrees);
}