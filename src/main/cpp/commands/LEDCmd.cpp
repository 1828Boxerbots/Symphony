// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LEDCmd.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>

#include <subsystems/LoaderSub.h>

LEDCmd::LEDCmd(LEDSub *pSub, frc::XboxController* pController) 
{
  m_pSub = pSub;
  m_pController = pController;

  AddRequirements(m_pSub);
}

// Called when the command is initially scheduled.
void LEDCmd::Initialize() 
{
    m_Timer.Start();

    if (frc::DriverStation::GetAlliance() == frc::DriverStation::Alliance::kRed)
        m_allianceColor = AllianceColor::RED;
    else
        m_allianceColor = AllianceColor::BLUE;
}

// Called repeatedly when this Command is scheduled to run
void LEDCmd::Execute() 
{
    // Toggle HP signal on/off
    if (m_pController->GetBButtonPressed())
    {
        m_toggleTopSignal = !m_toggleTopSignal;
    }

    // Flash when 10 seconds left
    if ((double)frc::DriverStation::GetMatchTime() < 10.0)
    {
        if (m_CurrentFlashCount > m_flashCounts)
        {
            m_CurrentFlashCount = 0;
            m_FlashOn = !m_FlashOn;
        }

        if (!m_FlashOn)
        {
            m_pSub->SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 0, 0, 0);
        }
        else
        {
            switch (m_allianceColor)
            {
            case AllianceColor::RED:
                m_pSub->SetRangeRGB(0, 118, 255, 0, 0);
                break;
            case AllianceColor::BLUE:
                m_pSub->SetRangeRGB(0, 118, 0, 0, 255);
                break;
            default:
                break;
            }
        }
        
        m_CurrentFlashCount++;
    }
    else
    {
        
    }

    m_pSub->ApplyBuffer();
}

// Called once the command ends or is interrupted.
void LEDCmd::End(bool interrupted) 
{
  switch (m_allianceColor)
  {
  case AllianceColor::RED:
    m_pSub->SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 255, 0, 0);
    break;
  case AllianceColor::BLUE:
    m_pSub->SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 0, 0, 255);
  default:
    break;
  }

  m_Timer.Stop();
  m_Timer.Reset();
}

// Returns true when the command should end.
bool LEDCmd::IsFinished() {
  return m_isFinished;
}
