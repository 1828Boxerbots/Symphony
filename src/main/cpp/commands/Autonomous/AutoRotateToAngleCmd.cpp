#include "commands/Autonomous/AutoRotateToAngleCmd.h"

#include "Util.h"
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
    if (m_Angle < 0.0)
        m_pDriveSub->DriveTank(m_Speed, -m_Speed);
    else
        m_pDriveSub->DriveTank(-m_Speed, m_Speed);
}

void AutoRotateToAngleCmd::End(bool interrupted)
{
    m_pDriveSub->DriveTank(0.0, 0.0);
}

bool AutoRotateToAngleCmd::IsFinished()
{
    if (fabs(m_pDriveSub->GetYaw()) >= fabs(m_Angle))
    {
        return true;
    }

    return false;
}