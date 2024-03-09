// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LEDSub.h"
#include <frc/smartdashboard/SmartDashboard.h>

LEDSub::LEDSub()
{
    
}

void LEDSub::Init()
{
    m_AddressableLED.SetLength(OperatorConstants::PIXEL_COUNT);
    m_AddressableLED.SetData(m_PixelBuffer);
    m_AddressableLED.Start();
}

// This method will be called once per scheduler run
void LEDSub::Periodic() 
{
    for (int i = 0; i < OperatorConstants::PIXEL_COUNT; i++)
        m_PixelBuffer[i].SetRGB(0, 0, 255);

    m_AddressableLED.SetData(m_PixelBuffer);
}