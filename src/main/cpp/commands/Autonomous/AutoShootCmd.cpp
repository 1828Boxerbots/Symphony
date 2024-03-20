#include "commands/Autonomous/AutoShootCmd.h"

AutoShootCmd::AutoShootCmd(ShooterSub* shooter, LoaderSub* loader)
{
    m_pShooterSub = shooter;
    m_pLoaderSub = loader;

    AddRequirements(m_pShooterSub);
    AddRequirements(m_pLoaderSub);
}

void AutoShootCmd::Initialize()
{
    
}

void AutoShootCmd::Execute()
{
    if (!m_pLoaderSub->GetPhotoGate())
    {
        m_IsFinished = true;
        return;
    }

    if ((m_pShooterSub == nullptr) || m_pLoaderSub == nullptr)
    {
        m_IsFinished = true; 
        return;
    }
    
    double targetSpeed = 1.0;
    double targetRPM = OperatorConstants::NEO_MAX_OPENLOAD_RPM * targetSpeed; // Calculates the target RPM with no load
    double loadFactor = targetRPM * OperatorConstants::NEO_LOAD_FACTOR;       // Calculates the affect of load on the motors
    targetRPM -= loadFactor;                                                  // Applies the load factor to give target RPM with load factor
    
    // The first item is left motor, right is second
    std::pair<double, double> motorRPM = m_pShooterSub->GetMotorRPM();
    double avgRPM = ((fabs(motorRPM.first) + fabs(motorRPM.second)) / 2.0);
    
    m_pShooterSub->Shoot(-targetSpeed);
    
    if (avgRPM >= targetRPM)
        m_pLoaderSub->Load(0.7);
}

void AutoShootCmd::End(bool interrupted)
{
    m_pShooterSub->Shoot(0.0);
    m_IsFinished = false;
}

bool AutoShootCmd::IsFinished()
{
    return m_IsFinished;
}