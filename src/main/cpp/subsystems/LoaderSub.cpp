// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoaderSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include <iostream>

frc::DigitalInput LoaderSub::m_photogate = frc::DigitalInput(OperatorConstants::kSymphonyLoaderPhotogate);

LoaderSub::LoaderSub() = default;

// This method will be called once per scheduler run
void LoaderSub::Periodic() 
{
    // frc::SmartDashboard::PutNumber("Photogate Value", m_photogate.Get());
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
    if (m_motor.GetMotorTemperature() >= 60.0)
        m_motor.Set(0.0);
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================

    m_motor.Set(speed);
}

bool LoaderSub::GetPhotoGate()
{
    return m_photogate.Get();
}
