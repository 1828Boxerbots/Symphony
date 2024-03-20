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

void ShooterSub::ZeroSensors()
{
    m_EncoderLeft.SetPosition(0.0);
    m_EncoderRight.SetPosition(0.0);
}