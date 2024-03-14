// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include "Util.h"

ShooterSub::ShooterSub() = default;

// This method will be called once per scheduler run
void ShooterSub::Periodic() 
{
    // NOTE: Only enable during debugging (will slow down the hardware)

    // double encoderLDistance = m_encoderL.GetDistance();
    // double encoderRDistance = m_encoderR.GetDistance();
    // double encoderLRaw = m_encoderL.GetRaw();
    // double encoderRRaw = m_encoderR.GetRaw();
    // double encoderLDistPerPulse = m_encoderL.GetDistancePerPulse();
    // double encoderRDistPerPulse = m_encoderR.GetDistancePerPulse();

    // frc::SmartDashboard::PutNumber("Left Encoder Distance", encoderLDistance); //unknown if needed
    // frc::SmartDashboard::PutNumber("Right Encoder Distance", encoderRDistance); //unknown if needed
    // frc::SmartDashboard::PutNumber("Left Encoder Raw", encoderLRaw);
    // frc::SmartDashboard::PutNumber("Right Encoder Raw", encoderRRaw);
    // frc::SmartDashboard::PutNumber("Left Encoder DistPerPulse", encoderLDistPerPulse);
    // frc::SmartDashboard::PutNumber("Right Encoder DistPerPulse", encoderRDistPerPulse);
    // frc::SmartDashboard::PutNumber("Pulses Per Encoder", m_pulses);

    // frc::SmartDashboard::PutNumber("Left Speed", m_EncoderLeft.GetVelocity());
    // frc::SmartDashboard::PutNumber("Right Speed", m_EncoderRight.GetVelocity());
}

void ShooterSub::Init()
{
    // Invert appropriate motors
    m_motorL.SetInverted(true);

    // Stop all motors
    m_motorL.Set(0.0);
    m_motorR.Set(0.0);
}

void ShooterSub::Shoot(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);
}

std::pair<double, double> ShooterSub::GetMotorRPM()
{
    double leftRPM = m_EncoderLeft.GetVelocity();
    double rightRPM = m_EncoderRight.GetVelocity();

    return std::pair<double, double>(leftRPM, rightRPM);
}

double ShooterSub::CalculateSpeed(double distanceToTarget)
{
    const double shooterAngle = 50; //in degrees
    const double initialHeight = 0.38734643; //in meters
    const double gravity = -9.8; //in m/s^2
    double initialVelocity; //the initial needed velocity for shooter
    double numerator; //denominator of equation to find initial velocity
    double denominator; //denominator of equation to find initial velocity
    double rotationsPerMinute; //target rotations per minute based off of calculations
    double radius = 0.0508; //in meters, placeholder value until confirmed
    double angleRad = Util::ConvertToRadians(shooterAngle); //converting angle in degrees to radians for calculation
    double maxMotorRPM = 5676; //The max amount of rotations per minute of the given motor
    double motorSpeed; //speed to set motor to based off of calculations

    numerator = gravity * (distanceToTarget * distanceToTarget); 
    denominator = 2.0 * std::cos(angleRad) * ((-initialHeight * std::cos(angleRad)) - (distanceToTarget * std::sin(angleRad))); //TBD what 2 means
    initialVelocity = numerator/denominator; 
    rotationsPerMinute = (initialVelocity/radius)/(2.0 * OperatorConstants::PI);

    Util::Log("CalculateSpeed", motorSpeed, GetName());
    
    return motorSpeed;

}

void ShooterSub::ZeroSensors()
{
    m_EncoderLeft.SetPosition(0.0);
    m_EncoderRight.SetPosition(0.0);
}