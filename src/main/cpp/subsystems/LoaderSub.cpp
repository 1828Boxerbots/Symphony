// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoaderSub.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/RobotController.h>

#include <iostream>

frc::DigitalInput LoaderSub::m_photogate = frc::DigitalInput(OperatorConstants::kSymphonyLoaderPhotogate);
bool LoaderSub::m_SafetyEngaged = false;
frc::AnalogInput LoaderSub::m_ultrasonic = frc::AnalogInput(OperatorConstants::kSymphonyLoaderUltrasonic);

LoaderSub::LoaderSub() = default;

// This method will be called once per scheduler run
void LoaderSub::Periodic() 
{
    // frc::SmartDashboard::PutNumber("Photogate Value", m_photogate.Get());
    // frc::SmartDashboard::PutNumber("Loader Temp", m_motor.GetMotorTemperature());

    frc::SmartDashboard::PutNumber("Ultrasonic Value", GetUltrasonicDistance());

    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================
    if (m_SafetyEngaged && m_motor.GetMotorTemperature() < (OperatorConstants::MOTOR_CUTOFF_TEMP - 10))
    {
        m_SafetyEngaged = false;
    }
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================
}

void LoaderSub::Init()
{
    // Invert necessary motors
    m_motor.SetInverted(true);
}

void LoaderSub::Load(double speed)
{
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================
    if (m_motor.GetMotorTemperature() >= OperatorConstants::MOTOR_CUTOFF_TEMP)
    {
        m_motor.Set(0.0);
        m_SafetyEngaged = true;
    }
    // What for safety disengage as motors are still cooling down
    else if (!m_SafetyEngaged)
    {
        m_motor.Set(speed);
    }
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================
}

bool LoaderSub::GetPhotoGate()
{
    return m_photogate.Get();
}

bool LoaderSub::GetSafetyEngaged()
{
    return m_SafetyEngaged;
}

double LoaderSub::GetUltrasonicDistance()
{
    double voltageFactor = 5.0 / frc::RobotController::GetVoltage5V();  // Accounts for power fluctuations in the 5V rail
    return m_ultrasonic.GetValue() * voltageFactor * 0.0492;
}