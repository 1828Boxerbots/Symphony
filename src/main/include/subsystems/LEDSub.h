// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>

#include "Constants.h"

class LEDSub : public frc2::SubsystemBase {
 public:
  LEDSub();

  void Init();
  
  void Periodic() override;

 private:
    frc::AddressableLED m_AddressableLED {OperatorConstants::kLEDPort};
    std::array<frc::AddressableLED::LEDData, OperatorConstants::PIXEL_COUNT> m_PixelBuffer;
};
