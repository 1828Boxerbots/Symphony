// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSub.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Util.h"

ShooterSub::ShooterSub()
{
    SetName("ShooterSub");
}

// This method will be called once per scheduler run
void ShooterSub::Periodic() 
{
    Util::Log("Pulses Per Encoder", m_pulses, GetName());
}

void ShooterSub::Init()
{
    
    
    m_motorL.SetInverted(true);

}

void ShooterSub::Shoot(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);

}

double ShooterSub::CalculateSpeed(double distanceToTarget)
{
    const double shooterAngle = 35; //in degrees, placeholder value
    const double initialHeight = 0.4572; //in meters, placeholder value
    const double gravity = -9.8; //in m/s^2
    double initialVelocity; //the initial needed velocity for shooter
    double numerator; //denominator of equation to find initial velocity
    double denominator; //denominator of equation to find initial velocity
    double rotationsPerMinute; //target rotations per minute based off of calculations
    double radius = 0.0508; //in meters, placeholder value until confirmed
    double angleRad = Util::ConvertToRadians(shooterAngle); //converting angle in degrees to radians for calculation
    double maxMotorRPM = 5676; //The max amount of rotations per minute of the given motor
    double motorSpeed; //speed to set motor to based off of calculations

    numerator = gravity * (distanceToTarget * distanceToTarget); 
    denominator = 2.0 * std::cos(angleRad) * ((-initialHeight * std::cos(angleRad)) - (distanceToTarget * std::sin(angleRad))); //TBD what 2 means
    initialVelocity = numerator/denominator; 
    rotationsPerMinute = (initialVelocity/radius)/(2.0 * OperatorConstants::PI);
    motorSpeed = rotationsPerMinute/maxMotorRPM; 

    Util::Log("CalculateSpeed", motorSpeed, GetName());
    
    return motorSpeed;

}

double ShooterSub::GetSpeed()
{
    double left = m_motorL.GetAlternateEncoder(m_pulses).GetVelocity(); 
    double right = m_motorR.GetAlternateEncoder(m_pulses).GetVelocity(); 

    Util::Log("Left Motor Speed", left, GetName());
    Util::Log("Right Motor Speed", right, GetName());

    if(left == 0.0)
    {
        return right;
    }
    return left;
    

}

   