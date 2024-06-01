// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/Encoder.h>
#include <frc/motorcontrol/Victor.h>
#include <Constants.h>
#include <rev/CANSparkMax.h> 
#include <math.h>

#include <utility>

class ShooterSub : public frc2::SubsystemBase {
 public:
    ShooterSub();

    void Init();

    void Periodic() override;

    /// @brief Used to set the speed of the shooter motors.
    /// @param speed The speed at which the motors will move.
    void Shoot(double speed);

    /// @brief Returns the current RPM of both shooter motors.
    /// @return A std::pair that contains the motor RPM. The first element is
    ///         the left motor RPM and the second element is the right motor.
    std::pair<double, double> GetMotorRPM();

    /// @brief Calculates the desired motor speed based on distance.
    /// @param distanceToTarget The distance to the target in meters.
    /// @return The percentage of motor power to run and the corresponding RPM.
    std::pair<double, double> CalculateSpeed(double distanceToTarget);

    /// @brief Called to reset any subsystem sensitive sensors.
    void ZeroSensors();

 private:

    rev::CANSparkMax m_motorL {OperatorConstants::kSymphonyShooterIDL, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_motorR {OperatorConstants::kSymphonyShooterIDR, rev::CANSparkMax::MotorType::kBrushless};  

    rev::SparkRelativeEncoder m_EncoderLeft = m_motorL.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
    rev::SparkRelativeEncoder m_EncoderRight = m_motorR.GetEncoder(rev::SparkRelativeEncoder::Type::kHallSensor);
};
