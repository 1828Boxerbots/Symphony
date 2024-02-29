// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/AutoSwitchSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

AutoSwitchSub::AutoSwitchSub() = default;

// This method will be called once per scheduler run
void AutoSwitchSub::Periodic() 
{
}

void AutoSwitchSub::Init()
{
}

AutonomousMode AutoSwitchSub::GetSelectedMode()
{
    // NOTE: With a 3 position switch the possible cases are (TF, FF, and FT).

    if (m_SwitchHigh.Get() && !m_SwitchLow.Get())
        return AutonomousMode::POS1;
    else if (!m_SwitchHigh.Get() && !m_SwitchLow.Get())
        return AutonomousMode::POS2;
    else if (!m_SwitchHigh.Get() && m_SwitchLow.Get())
        return AutonomousMode::POS3;
}