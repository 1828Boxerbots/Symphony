// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/BatonSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

BatonSub::BatonSub() = default;

// This method will be called once per scheduler run
void BatonSub::Periodic() 
{
    // NOTE: Only used for outputing values to smart dashboard during debugging
    frc::SmartDashboard::PutNumber("Encoder Rotations", m_EncoderL.GetPosition());
    frc::SmartDashboard::PutBoolean("Upper Hall Effect", m_UpperHallEffect.Get());
}

void BatonSub::Init()
{
    m_motorR.SetInverted(true);

    m_PIDLeft.SetOutputRange(m_kMinOutput, m_kMaxOutput);
    m_EncoderL.SetPosition(0.0);    // Reset the encoder at the rest position
}

void BatonSub::Stop()
{
    m_motorL.Set(0.0);
    m_motorR.Set(0.0);
} 

void BatonSub::MoveToExtended(double speed)
{

}

void BatonSub::MoveToStowed(double speed)
{
    
}

void BatonSub::SetMotor(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);
} 

void BatonSub::ZeroSensors()
{
    m_EncoderL.SetPosition(0.0);
}