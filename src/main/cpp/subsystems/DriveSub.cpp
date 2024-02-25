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

    // motor encoders
    // Util::Log("MotorEncoderL1-dist", GetDistanceL1(), GetName());
    // Util::Log("MotorEncoderL2-dist", GetDistanceL2(), GetName());
    // Util::Log("MotorEncoderR1-dist", GetDistanceR1(), GetName());
    // Util::Log("MotorEncoderR2-dist", GetDistanceR2(), GetName());
    // Util::Log("MotorEncoderL1-speed", GetSpeedL1(), GetName());
    // Util::Log("MotorEncoderL2-speed", GetSpeedL2(), GetName());
    // Util::Log("MotorEncoderR1-speed", GetSpeedR1(), GetName());
    // Util::Log("MotorEncoderR2-speed", GetSpeedR2(), GetName());

    // Util::Log("MotorEncoderL1-avgDepth", GetEncoderL1().GetAverageDepth(), GetName());
    // Util::Log("MotorEncoderL2-avgDepth", GetEncoderL2().GetAverageDepth(), GetName());
    // Util::Log("MotorEncoderR1-avgDepth", GetEncoderR1().GetAverageDepth(), GetName());
    // Util::Log("MotorEncoderR2-avgDepth", GetEncoderR2().GetAverageDepth(), GetName());

    // Util::Log("MotorEncoderL1-cntPerRev", GetEncoderL1().GetCountsPerRevolution(), GetName());
    // Util::Log("MotorEncoderL2-cntPerRev", GetEncoderL2().GetCountsPerRevolution(), GetName());
    // Util::Log("MotorEncoderR1-cntPerRev", GetEncoderR1().GetCountsPerRevolution(), GetName());
    // Util::Log("MotorEncoderR2-cntPerRev", GetEncoderR2().GetCountsPerRevolution(), GetName());

    // Util::Log("MotorEncoderL1-inverted", GetEncoderL1().GetInverted(), GetName());
    // Util::Log("MotorEncoderL2-inverted", GetEncoderL2().GetInverted(), GetName());
    // Util::Log("MotorEncoderR1-inverted", GetEncoderR1().GetInverted(), GetName());
    // Util::Log("MotorEncoderR2-inverted", GetEncoderR2().GetInverted(), GetName());

    // Util::Log("MotorEncoderL1-measPeriod", GetEncoderL1().GetMeasurementPeriod(), GetName());
    // Util::Log("MotorEncoderL2-measPeriod", GetEncoderL2().GetMeasurementPeriod(), GetName());
    // Util::Log("MotorEncoderR1-measPeriod", GetEncoderR1().GetMeasurementPeriod(), GetName());
    // Util::Log("MotorEncoderR2-measPeriod", GetEncoderR2().GetMeasurementPeriod(), GetName());

    // Util::Log("MotorEncoderL1-posConvFactor", GetEncoderL1().GetPositionConversionFactor(), GetName());
    // Util::Log("MotorEncoderL2-posConvFactor", GetEncoderL2().GetPositionConversionFactor(), GetName());
    // Util::Log("MotorEncoderR1-posConvFactor", GetEncoderR1().GetPositionConversionFactor(), GetName());
    // Util::Log("MotorEncoderR2-posConvFactor", GetEncoderR2().GetPositionConversionFactor(), GetName());

    // Util::Log("MotorEncoderL1-velConvFactor", GetEncoderL1().GetVelocityConversionFactor(), GetName());
    // Util::Log("MotorEncoderL2-velConvFactor", GetEncoderL2().GetVelocityConversionFactor(), GetName());
    // Util::Log("MotorEncoderR1-velConvFactor", GetEncoderR1().GetVelocityConversionFactor(), GetName());
    // Util::Log("MotorEncoderR2-velConvFactor", GetEncoderR2().GetVelocityConversionFactor(), GetName());

    // IMU
    // Util::Log("IMU-angleX", GetAngleX(), GetName());
    // Util::Log("IMU-angleY", GetAngleY(), GetName());
    // Util::Log("IMU-angleZ", GetAngleZ(), GetName());
    // Util::Log("IMU-angle", (double)m_imu.GetAngle(), GetName());

    // Util::Log("IMU-barPressure", (double)m_imu.GetBarometricPressure(), GetName());
    // Util::Log("IMU-magFluxX", (double)m_imu.GetMagneticFieldX(), GetName());
    // Util::Log("IMU-magFluxY", (double)m_imu.GetMagneticFieldY(), GetName());
    // Util::Log("IMU-magFluxZ", (double)m_imu.GetMagneticFieldZ(), GetName());
    // Util::Log("IMU-temperature", (double)m_imu.GetTemperature(), GetName());
    // Util::Log("IMU-xCompAngle", (double)m_imu.GetXComplementaryAngle(), GetName());
    // Util::Log("IMU-yCompAngle", (double)m_imu.GetYComplementaryAngle(), GetName());
    // Util::Log("IMU-xAccelAngle", (double)m_imu.GetXFilteredAccelAngle(), GetName());
    // Util::Log("IMU-yAccelAngle", (double)m_imu.GetYFilteredAccelAngle(), GetName());
    // Util::Log("IMU-yAxis", (double)m_imu.GetYawAxis(), GetName());
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
}

void DriveSub::DriveTank(double left, double right)
{
    m_motorR1.Set(right);
    m_motorR2.Set(right);
    m_motorL1.Set(left);
    m_motorL2.Set(left);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    double dampFactor = 0.8;
    double dampedHoriz = horizontal * dampFactor;

    DriveTank(vertical+dampedHoriz, vertical-dampedHoriz);
}

///////////////////////////////////////////////////////////////////////////////
// ENCODERS
// double DriveSub::GetDistanceL1()
// {
//     return m_leftEncoder1.GetPosition();
// }
// double DriveSub::GetDistanceL2()
// {
//     return m_leftEncoder2.GetPosition();
// }
// double DriveSub::GetDistanceR1()
// {
//     return m_rightEncoder1.GetPosition();
// }
// double DriveSub::GetDistanceR2()
// {
//     return m_rightEncoder2.GetPosition();
// }
// double DriveSub::GetSpeedL1()
// {
//     return m_leftEncoder1.GetVelocity();
// }
// double DriveSub::GetSpeedL2()
// {
//     return m_leftEncoder2.GetVelocity();
// }
// double DriveSub::GetSpeedR1()
// {
//     return m_rightEncoder1.GetVelocity();
// }
// double DriveSub::GetSpeedR2()
// {
//     return m_rightEncoder2.GetVelocity();
// }

///////////////////////////////////////////////////////////////////////////////
// IMU
// double DriveSub::GetAngle()
// {
//     return GetAngleX();
// }
// double DriveSub::GetAngleX()
// {
//     return (double)m_imu.GetGyroAngleX();;
// }
// double DriveSub::GetAngleY()
// {
//     return (double)m_imu.GetGyroAngleY();;
// }
// double DriveSub::GetAngleZ()
// {
//     return (double)m_imu.GetGyroAngleZ();;
// }
