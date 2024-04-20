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

    m_IsFinished = false;
}

void AutoMoveForwardDistanceCmd::Execute()
{
    m_pDriveSub->DriveDistancePID(m_Distance);
}

void AutoMoveForwardDistanceCmd::End(bool interrupted)
{
    std::cout << "Finished" << std::endl;
    m_pDriveSub->DriveTank(0.0, 0.0);
}

bool AutoMoveForwardDistanceCmd::IsFinished()
{
    frc::SmartDashboard::PutNumber("Avg Distance", m_pDriveSub->GetAvgDistance());

    if (m_pDriveSub->GetAvgDistance() > (m_Distance - 4))
    {
        return true;
    }

    return false;
}