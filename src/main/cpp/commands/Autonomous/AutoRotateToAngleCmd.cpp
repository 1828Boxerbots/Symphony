#include "commands/Autonomous/AutoRotateToAngleCmd.h"

#include <iostream>

AutoRotateToAngleCmd::AutoRotateToAngleCmd(DriveSub* sub, double speed, double angle)
{
    m_pDriveSub = sub;
    m_Speed = speed;
    m_Angle = angle;

    AddRequirements(m_pDriveSub);
}

void AutoRotateToAngleCmd::Initialize()
{
    m_pDriveSub->SetPIDSpeed(m_Speed);
    m_pDriveSub->ZeroSensors();
}

void AutoRotateToAngleCmd::Execute()
{
    if (m_pDriveSub->GetYaw() > m_Angle)
    {
        m_IsFinished = true;
        return;
    }

    if (m_Angle < 0.0)
        m_pDriveSub->DriveTank(m_Speed, -m_Speed);
    else
        m_pDriveSub->DriveTank(-m_Speed, m_Speed);
}

void AutoRotateToAngleCmd::End(bool interrupted)
{
    m_pDriveSub->DriveTank(0.0, 0.0);
    m_IsFinished = false;
}

bool AutoRotateToAngleCmd::IsFinished()
{
    return m_IsFinished;
}