// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"
#include "Util.h"

DriveSub::DriveSub()
{
    SetName("DriveSub");
}

// This method will be called once per scheduler run
void DriveSub::Periodic()
{
    // NOTE: Only enable during debugging (will slow down the hardware)
    //frc::SmartDashboard::PutNumber("Encoder Distance (in)", GetAvgDistance());
}

void DriveSub::Init()
{
    // invert apprpriate motors
    m_motorR1.SetInverted(true);
    m_motorR2.SetInverted(true);
    m_motorL1.SetInverted(false);
    m_motorL2.SetInverted(false);
    
    // stop all motors
    m_motorR1.Set(0.0);
    m_motorR2.Set(0.0);
    m_motorL1.Set(0.0);
    m_motorL2.Set(0.0);

    // Setup Encoders
    const double wheelDiameter = 6.0; // inches
    const double gearRatio = 8.46 / 1.0;
    double distPerPulse = Util::CalculateDistPerPulse(wheelDiameter, OperatorConstants::NEO_ENCODER_COUNT, gearRatio);

    m_leftEncoder1.SetPositionConversionFactor(distPerPulse);
    m_leftEncoder2.SetPositionConversionFactor(distPerPulse);
    m_rightEncoder1.SetPositionConversionFactor(distPerPulse);
    m_rightEncoder2.SetPositionConversionFactor(distPerPulse);

    // Setup PIDs
    m_leftPID1.SetP(m_kP);
    m_leftPID1.SetI(m_kI);
    m_leftPID1.SetD(m_kD);
    m_leftPID1.SetIZone(m_kIZ);
    m_leftPID1.SetFF(m_kF);

    m_leftPID2.SetP(m_kP);
    m_leftPID2.SetI(m_kI);
    m_leftPID2.SetD(m_kD);
    m_leftPID2.SetIZone(m_kIZ);
    m_leftPID2.SetFF(m_kF);

    m_rightPID1.SetP(m_kP);
    m_rightPID1.SetI(m_kI);
    m_rightPID1.SetD(m_kD);
    m_rightPID1.SetIZone(m_kIZ);
    m_rightPID1.SetFF(m_kF);

    m_rightPID2.SetP(m_kP);
    m_rightPID2.SetI(m_kI);
    m_rightPID2.SetD(m_kD);
    m_rightPID2.SetIZone(m_kIZ);
    m_rightPID2.SetFF(m_kF);
}

void DriveSub::DriveTank(double left, double right)
{
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================
    if (m_motorL1.GetMotorTemperature() >= 60.0 || m_motorL2.GetMotorTemperature() >= 60.0)
    {
        m_motorL1.Set(0.0);
        m_motorL2.Set(0.0);
    }

    if (m_motorR1.GetMotorTemperature() >= 60.0 || m_motorR2.GetMotorTemperature() >= 60.0)
    {
        m_motorR1.Set(0.0);
        m_motorR2.Set(0.0);
    }
    // ===============================================
    //          BEGIN SAFETY CRITICAL CODE
    // ===============================================

    m_motorR1.Set(right);
    m_motorR2.Set(right);
    m_motorL1.Set(left);
    m_motorL2.Set(left);
}

void DriveSub::DriveDistancePID(double dist)
{
    m_leftPID1.SetReference(dist, rev::CANSparkMax::ControlType::kPosition);
    m_leftPID2.SetReference(dist, rev::CANSparkMax::ControlType::kPosition);
    m_rightPID1.SetReference(dist, rev::CANSparkMax::ControlType::kPosition);
    m_rightPID2.SetReference(dist, rev::CANSparkMax::ControlType::kPosition);
}

void DriveSub::SetPIDSpeed(double speed)
{
    m_leftPID1.SetOutputRange(-speed, speed);
    m_leftPID2.SetOutputRange(-speed, speed);
    m_rightPID1.SetOutputRange(-speed, speed);
    m_rightPID2.SetOutputRange(-speed, speed);
}

double DriveSub::GetAvgDistance()
{
    double factor = 0.95;

    double leftDist1 = m_leftEncoder1.GetPosition() * factor;
    double leftDist2 = m_leftEncoder2.GetPosition() * factor;
    double rightDist1 = m_rightEncoder1.GetPosition();
    double rightDist2 = m_rightEncoder2.GetPosition();

    return (leftDist1 + leftDist2 + rightDist1 + rightDist2) / 4.0;
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    double dampFactor = 0.8;
    double dampedHoriz = horizontal * dampFactor;

    DriveTank(vertical+dampedHoriz, vertical-dampedHoriz);
}

void DriveSub::ZeroSensors()
{
    m_leftEncoder1.SetPosition(0.0);
    m_leftEncoder2.SetPosition(0.0);
    m_rightEncoder1.SetPosition(0.0);
    m_rightEncoder2.SetPosition(0.0);
}