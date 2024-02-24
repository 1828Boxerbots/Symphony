// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSub.h"
#include "Util.h"

VisionSub::VisionSub()
{
    SetName("VisionSub");
}

// This method will be called once per scheduler run
void VisionSub::Periodic() 
{

}

void VisionSub::Init()
{
    
}

double VisionSub::GetTargYaw(int id)
{
    if (id == m_idRequested)
    {
        return m_targetYaw;
    } else if (id == m_idRequested2)
    {
        return m_targetYaw2;
    }
    return 0.0;
}
  
double VisionSub::GetTargSkew(int id)
{
    if (id == m_idRequested)
    {
        return m_targetSkew;
    } else if (id == m_idRequested2)
    {
        return m_targetSkew2;
    }
    return 0.0;
}
  
double VisionSub::GetTargArea(int id)
{
    if (id == m_idRequested)
    {
        return m_targetArea;
    } else if (id == m_idRequested2)
    {
        return m_targetArea2;
    }
    return 0.0;
}

units::meter_t VisionSub::GetTargDist(int id)
{
    if (id == m_idRequested)
    {
        return m_targetDist;
    } else if (id == m_idRequested2)
    {
        return m_targetDist2;
    }
    return 0.0_m;
}
