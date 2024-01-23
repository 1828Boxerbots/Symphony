// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

ShooterSub::ShooterSub() = default;

// This method will be called once per scheduler run
void ShooterSub::Periodic() 
{
    double encoderLDistance = m_encoderL.GetDistance();
    double encoderRDistance = m_encoderR.GetDistance();
    double encoderLRaw = m_encoderL.GetRaw();
    double encoderRRaw = m_encoderR.GetRaw();
    double encoderLDistPerPulse = m_encoderL.GetDistancePerPulse();
    double encoderRDistPerPulse = m_encoderR.GetDistancePerPulse();

    frc::SmartDashboard::PutNumber("Left Encoder Distance", encoderLDistance); //unknown if needed
    frc::SmartDashboard::PutNumber("Right Encoder Distance", encoderRDistance); //unknown if needed
    frc::SmartDashboard::PutNumber("Left Encoder Raw", encoderLRaw);
    frc::SmartDashboard::PutNumber("Right Encoder Raw", encoderRRaw);
    frc::SmartDashboard::PutNumber("Left Encoder DistPerPulse", encoderLDistPerPulse);
    frc::SmartDashboard::PutNumber("Right Encoder DistPerPulse", encoderRDistPerPulse);
    frc::SmartDashboard::PutNumber("Pulses Per Encoder", m_pulses);


}

void ShooterSub::Init()
{
    
    
    double diameter = 4; //placeholder diameter, real not yet known
    double distPerPulse = 3.14159 * diameter/m_pulses;
    m_motorL.SetInverted(true);
    m_encoderL.SetDistancePerPulse(distPerPulse);
    m_encoderR.SetDistancePerPulse(distPerPulse);

}

void ShooterSub::Shoot(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);

}


