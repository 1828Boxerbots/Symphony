// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <NetworkTables/NetworkTable.h>
#include <units/length.h>
#include <string>
#include "subsystems/VisionSub.h"
#include "Util.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

VisionSub::VisionSub()
{
    SetName("VisionSub");
}

// This method will be called once per scheduler run
void VisionSub::Periodic() 
{
    // double start = (double)m_timer.Get();
    
    Util::Log("dist(in inches)", (double)GetDistanceInInches(10), GetName());

    // double total = (double)m_timer.Get() - start;
    //Util::Log("periodic(msec)", total*1000.0, GetName());
}

void VisionSub::Init()
{
    cs::UsbCamera camera = frc::CameraServer::StartAutomaticCapture();
    camera.SetResolution(640, 480);
    camera.SetBrightness(50);
    camera.SetExposureAuto();
    camera.SetFPS(15);
}

double VisionSub::GetBestYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }
    return result.GetBestTarget().GetYaw();
}

double VisionSub::GetYaw()
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (result.HasTargets() == false)
    {
        return 0.0;
    }

    int id1;
    int id2;
    double yaw1;
    double yaw2;
    int numTargets = NumValidTargets(&id1, &id2, &yaw1, &yaw2);
    if (numTargets == 0)
    {
        // no VALID targets found
        return 0.0;
    }

    // find specific ID
    if (numTargets == 1)
    {
        return yaw1;
    }

    if (id2 > id1)
    {
        // required ID to focus on is the larger ID
        return yaw2;
    }
    return 0.0;
}

bool VisionSub::HasTargets()
{
    return m_testCam.GetLatestResult().HasTargets();
}

int VisionSub::NumValidTargets(int *pTarget1Id, int *pTarget2Id, double *pYaw1, double *pYaw2)
{
    int targValidCount = 0;

    if (m_testCam.GetLatestResult().HasTargets() == false)
    {
        return 0;
    }

    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = m_testCam.GetLatestResult().GetTargets();

    for(unsigned i = 0; i < targets.size(); i++)
    {        
        int targID = targets[i].GetFiducialId();

        // valid target ID's are from 1 thru 16.
        if(targID >= 1 and targID <= m_kMaxTargetId)
        {
            targValidCount++;

            // output ID #'s and yaw's
            if (targValidCount == 1 and pTarget1Id != nullptr and pYaw1 != nullptr)
            {
                *pTarget1Id = targets[i].GetFiducialId();
                *pYaw1 = m_testCam.GetLatestResult().GetBestTarget().GetYaw();
            }
            else if (targValidCount == 2 and pTarget2Id != nullptr and pYaw2 != nullptr)
            {
                *pTarget2Id = targets[i].GetFiducialId();
                *pYaw2 = targets[i].GetYaw();
            }
        }
    }

    return targValidCount;
}

units::length::meter_t VisionSub::GetDistanceInMeters(int targetID)
{
    photon::PhotonPipelineResult result = m_testCam.GetLatestResult();
    if (!result.HasTargets())
    {
        return 0.0_m;
    }

    // get target info
    std::span<const photon::PhotonTrackedTarget, 4294967295U> targets = result.GetTargets();

    // find specific ID
    for(unsigned i=0; i<targets.size(); ++i)
    {
        //Util::Log(std::string("ID #") + std::to_string(i), targets[i].GetFiducialId(), GetName());

        //Util::Log(std::string("Dist #") + std::to_string(i), dist, GetName());
        if (targets[i].GetFiducialId() == targetID)
        {
            units::length::meter_t dist = (photon::PhotonUtils::CalculateDistanceToTarget (m_kCamHeight, GetTargetHeight(targetID), m_kCamPitch, (units::degree_t)targets[i].GetPitch()));
            //Util::Log("Final Dist", (double)dist, GetName());
            return dist;
        }
    }
    return 0.0_m;
}

units::length::inch_t VisionSub::GetDistanceInInches(int targetID)
{
    return (units::length::inch_t)GetDistanceInMeters(targetID);
}

units::length::meter_t VisionSub::GetTargetHeight(int id)
{
    units::length::inch_t centerOffset = 3.25_in;

    // for given target-ID, return height (needed for distance calculation)
    switch(id)
    {
        case 1:
            return 53.38_in - centerOffset; 
        case 2:
            return 53.38_in - centerOffset; 
        case 3:
            return 57.13_in - centerOffset; 
        case 4:
            return 57.13_in - centerOffset; 
        case 5:
            return 53.38_in - centerOffset; 
        case 6:
            return 53.38_in - centerOffset; 
        case 7:
            return 57.13_in - centerOffset; 
        case 8:
            return 57.13_in - centerOffset; 
        case 9:
            return 53.38_in - centerOffset; 
        case 10:
            return 53.38_in - centerOffset; 
        case 11:
            return 52.00_in - centerOffset; 
        case 12:
            return 52.00_in - centerOffset; 
        case 13:
            return 52.00_in - centerOffset; 
        case 14:
            return 52.00_in - centerOffset; 
        case 15:
            return 52.00_in - centerOffset;
        case 16:
            return 52.00_in - centerOffset;
    }
    return 0.0_m;
}

int VisionSub::GetTargID()
{
    return m_testCam.GetLatestResult().GetTargets()[0].GetFiducialId();
}