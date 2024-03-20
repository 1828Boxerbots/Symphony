// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>
#include <frc/DigitalInput.h>

#include "Constants.h"

enum class AllianceColor
{
    RED,
    BLUE
};

class LEDSub : public frc2::SubsystemBase {
 public:
  LEDSub();

  void Init();
  
  void Periodic() override;

    void SetPixelRGB(unsigned int i, uint8_t r, uint8_t g, uint8_t b);
    void SetRangeRGB(unsigned int start, unsigned int end, uint8_t r, uint8_t g, uint8_t b);

    void ApplyBuffer();

    bool GetUltrasonic();

 private:
    frc::DigitalInput m_loadedSensor {OperatorConstants::kSymphonyLoaderUltrasonic};

    frc::AddressableLED m_AddressableLED {OperatorConstants::kLEDPort};
    std::array<frc::AddressableLED::LEDData, OperatorConstants::PIXEL_COUNT> m_PixelBuffer;
};
