// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"

DriveSub::DriveSub() = default;

// This method will be called once per scheduler run
void DriveSub::Periodic()
{
    
}

void DriveSub::Init()
{
    m_motorControlR1.SetInverted(true);
    m_motorControlR2.SetInverted(true);
    m_motorControlL1.SetInverted(false);
    m_motorControlL2.SetInverted(false);
    
    m_motorControlR1.Set(0.0);
    m_motorControlR2.Set(0.0);
    m_motorControlL1.Set(0.0);
    m_motorControlL2.Set(0.0);
}

void DriveSub::DriveTank(double left, double right)
{
    m_motorControlR1.Set(right);
    m_motorControlR2.Set(right);
    m_motorControlL1.Set(left);
    m_motorControlL2.Set(left);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    DriveTank(vertical+horizontal, vertical-horizontal);
}

