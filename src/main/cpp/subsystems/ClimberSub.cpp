// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimberSub.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

ClimberSub::ClimberSub() = default;

// This method will be called once per scheduler run
void ClimberSub::Periodic() 
{
    frc::SmartDashboard::PutNumber("CS Potentiameter", m_potentiometer.Get());
    frc::SmartDashboard::PutNumber("CS MotorL value", m_motorL.Get());
    frc::SmartDashboard::PutNumber("CS MotorR value", m_motorR.Get());
}



void ClimberSub::Init()
{
    m_motorR.SetInverted(true);
}

void ClimberSub::SetMotors(double speed)
{
    m_motorL.Set(speed);
    m_motorR.Set(speed);
}

void ClimberSub::Extend()
{
    double CurrAngle = GetPAngle();

    if(CurrAngle + OperatorConstants::kSymphonyClimberPotentiometerRestAngle >= OperatorConstants::kSymphonyClimberExtendedAngleLimit)
    {
      Stop();
    }
    else
    {
     SetMotors(OperatorConstants::kSymphonyClimberExtendedAngleLimit);
    }
   
}

void ClimberSub::Retract()
{
     double CurrAngle = GetPAngle();

    if(CurrAngle + OperatorConstants::kSymphonyClimberPotentiometerRestAngle <= OperatorConstants::kSymphonyClimberRetractedAngleLimit)
     {
        Stop();
     }
     else
     {
       SetMotors(-OperatorConstants::kSymphonyClimberMotorSpeed);
     }
    
}

double ClimberSub::GetPAngle()
{
    double angle = 0;
    angle =  m_potentiometer.Get();
}

void ClimberSub::Stop()
{
    SetMotors(0);
}


