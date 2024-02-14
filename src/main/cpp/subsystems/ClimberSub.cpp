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
     frc::SmartDashboard::PutNumber("Climber Sub Extend Magnet", m_extendMagnet.Get());
    frc::SmartDashboard::PutNumber("Climber Sub Retract Magnet", m_retractMagnet.Get());
    frc::SmartDashboard::PutNumber("Climber Sub Climber Magnet", m_climbingMagnet.Get());
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

bool ClimberSub::Extend() //Same as go to swing
{
   
 bool IsAtELimit = IsAtExtendLimit();

 double speed = OperatorConstants::kSymphonyClimberMotorSpeed;


    if(IsAtELimit == true) 
    {
        m_isClimbable = true;
        Stop();
    }
    else
    {
     SetMotors(speed);
    }

      return IsAtELimit; 
}

bool ClimberSub::Retract()
{
    bool isAtRLimit = IsAtRetractLimit();
    bool isAtClimb = IsAtClimbSensor();
    double speed = OperatorConstants::kSymphonyClimberMotorSpeed;

    if(m_isClimbable == true)
    {
        if (isAtClimb == true)
        {
            Stop();
            m_isClimbable = false;
        }
        else
        {
            SetMotors(-speed);
        }

        return isAtClimb;
    }
    else
    {

        if(isAtRLimit == true)
        {
          Stop();
        }
        else
        {
           SetMotors(-speed);
        }  

        return isAtRLimit;

    }

    
}



void ClimberSub::Stop()
{
    SetMotors(0);
}

bool ClimberSub::IsAtRetractLimit()
{
    return m_retractMagnet.Get();
}

bool ClimberSub::IsAtExtendLimit()
{
    return m_extendMagnet.Get();
}

bool ClimberSub::IsAtClimbSensor()
{
    return m_climbingMagnet.Get();
}