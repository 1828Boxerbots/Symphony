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
    // frc::SmartDashboard::PutNumber("Left Encoder Rotations", m_EncoderL.GetPosition());
    // frc::SmartDashboard::PutNumber("Right Encoder Rotations", m_EncoderR.GetPosition());
    // frc::SmartDashboard::PutBoolean("Upper Hall Effect", m_UpperHallEffect.Get());
}

void BatonSub::Init()
{
    m_motorR.SetInverted(true);

    m_EncoderL.SetPosition(0.0);    // Reset the encoder at the rest position

    m_PIDLeft.SetP(m_kP);
    m_PIDLeft.SetI(m_kI);
    m_PIDLeft.SetD(m_kD);
    m_PIDLeft.SetIZone(m_kIZ);
    m_PIDLeft.SetFF(m_kF);
    m_PIDLeft.SetOutputRange(m_kMinOutput, m_kMaxOutput);

    m_PIDRight.SetP(m_kP);
    m_PIDRight.SetI(m_kI);
    m_PIDRight.SetD(m_kD);
    m_PIDRight.SetIZone(m_kIZ);
    m_PIDRight.SetFF(m_kF);
    m_PIDRight.SetOutputRange(m_kMinOutput, m_kMaxOutput);
}

void BatonSub::Stop()
{
    m_motorL.Set(0.0);
    m_motorR.Set(0.0);
} 

void BatonSub::SetPosition(double pos)
{
    m_PIDLeft.SetReference(pos, rev::CANSparkMax::ControlType::kPosition);
    m_PIDRight.SetReference(pos, rev::CANSparkMax::ControlType::kPosition);
} 

void BatonSub::SetMotors(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);
} 

double BatonSub::GetAvgEncoderPos()
{
    double leftPos = m_EncoderL.GetPosition();
    double rightPos = m_EncoderR.GetPosition();

    return (leftPos + rightPos) / 2.0;
}

void BatonSub::ZeroSensors()
{
    m_EncoderL.SetPosition(0.0);
    m_EncoderR.SetPosition(0.0);
}