#include "commands/Autonomous/AutoShootCmd.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "Util.h"

AutoShootCmd::AutoShootCmd(ShooterSub* shooter, LoaderSub* loader)
{
    m_pShooterSub = shooter;
    m_pLoaderSub = loader;

    AddRequirements(m_pShooterSub);
    AddRequirements(m_pLoaderSub);
}

void AutoShootCmd::Initialize()
{
    m_TimerStarted = false;
    m_Timer.Reset();
}

void AutoShootCmd::Execute()
{
    if (!m_TimerStarted)
    {
        m_TimerStarted = true;
        m_Timer.Start();
    }

    double targetSpeed = 1.0;
    double targetRPM = OperatorConstants::NEO_MAX_OPENLOAD_RPM * targetSpeed; // Calculates the target RPM with no load
    double loadFactor = targetRPM * OperatorConstants::NEO_LOAD_FACTOR;       // Calculates the affect of load on the motors
    targetRPM -= loadFactor;                                                  // Applies the load factor to give target RPM with load factor
    
    // The first item is left motor, right is second
    std::pair<double, double> motorRPM = m_pShooterSub->GetMotorRPM();
    double avgRPM = ((fabs(motorRPM.first) + fabs(motorRPM.second)) / 2.0);
    
    m_pShooterSub->Shoot(-targetSpeed);
    
    // Reached target speed (load note into shooter)
    if (avgRPM >= targetRPM)
    {
        m_pLoaderSub->Load(0.7);
    }
}

void AutoShootCmd::End(bool interrupted)
{
    m_Timer.Stop();

    m_pShooterSub->Shoot(0.0);
    m_pLoaderSub->Load(0.0);
}

bool AutoShootCmd::IsFinished()
{
    // Check if we have ran out of time
    if (Util::FloatComp((double)m_Timer.Get(), 2.0))
    {
        return true;
    }

    // Check if note has been shot
    if (m_pLoaderSub->GetUltrasonicDistance() > OperatorConstants::ULTRASONIC_LOADED_DIST)
    {
        return true;
    }

    return false;
}