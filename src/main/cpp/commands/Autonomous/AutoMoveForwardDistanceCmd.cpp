#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"

#include <iostream>

AutoMoveForwardDistanceCmd::AutoMoveForwardDistanceCmd(DriveSub* sub, double speed, double distance)
{
    m_pDriveSub = sub;
    m_Speed = speed;
    m_Distance = distance;

    AddRequirements(m_pDriveSub);
}

void AutoMoveForwardDistanceCmd::Initialize()
{
    m_pDriveSub->SetPIDSpeed(m_Speed);
    m_pDriveSub->ZeroSensors();
}

void AutoMoveForwardDistanceCmd::Execute()
{
    if (m_pDriveSub->GetAvgDistance() > m_Distance)
    {
        m_IsFinished = true;
        return;
    }

    m_pDriveSub->DriveDistancePID(m_Distance);
    //m_pDriveSub->DriveTank(m_Speed, m_Speed);
}

void AutoMoveForwardDistanceCmd::End(bool interrupted)
{
    std::cout << "Finished" << std::endl;
    m_pDriveSub->DriveTank(0.0, 0.0);
    m_IsFinished = false;
}

bool AutoMoveForwardDistanceCmd::IsFinished()
{
    return m_IsFinished;
}