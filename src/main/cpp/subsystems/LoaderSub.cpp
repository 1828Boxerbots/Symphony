// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoaderSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

LoaderSub::LoaderSub() = default;

// This method will be called once per scheduler run
void LoaderSub::Periodic() 
{
    //bool photogateValue = m_photogate.Get();
    //frc::SmartDashboard::PutNumber("Photogate Value", photogateValue);
}

void LoaderSub::Init()
{
    // Invert necessary motors
    m_motor.SetInverted(true);
}

void LoaderSub::Load(double speed)
{
    m_motor.Set(speed);
}

bool LoaderSub::GetPhotoGate()
{
    return m_photogate.Get();
}

double LoaderSub::GetEncoderSpeed()
{
    return GetEncoder().GetVelocity();
}
