#include "subsystems/LEDSub.h"

#include <frc/DriverStation.h>
#include <frc/smartdashboard/SmartDashboard.h>

LEDSub::LEDSub()
{

}

void LEDSub::Init()
{
    m_AddressableLED.SetLength(OperatorConstants::PIXEL_COUNT);
    m_AddressableLED.SetData(m_PixelBuffer);
    m_AddressableLED.Start();

    // auto allianceColor = frc::DriverStation::GetAlliance();
    // if (allianceColor.value() == frc::DriverStation::Alliance::kRed)
    // {
    //     SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 255, 0, 0);
    // }
    // else
    // {
    //     SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 0, 0, 255);
    // }
}

void LEDSub::Periodic()
{
    // if (frc::DriverStation::IsDisabled())
    // {
    //     auto allianceColor = frc::DriverStation::GetAlliance();
    //     if (allianceColor.value() == frc::DriverStation::Alliance::kRed)
    //     {
    //         SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 255, 0, 0);
    //     }
    //     else
    //     {
    //         SetRangeRGB(0, OperatorConstants::PIXEL_COUNT - 1, 0, 0, 255);
    //     }

    //     ApplyBuffer();
    // }

    for (int i = 0; i < OperatorConstants::PIXEL_COUNT; i++)
    {
        const auto pixelHue = (m_CurPixelHue + (i * 180 / OperatorConstants::PIXEL_COUNT));
        m_PixelBuffer[i].SetHSV(pixelHue, 255, 128);
    }

    m_CurPixelHue += 3;
    m_CurPixelHue %= 180;

    ApplyBuffer();
}

void LEDSub::SetPixelRGB(unsigned int i, u_int8_t r, uint8_t g, uint8_t b)
{
    // Only index into allowed range
    if (i >= OperatorConstants::PIXEL_COUNT)
        return;

    m_PixelBuffer[i].SetRGB(r, g, b);
}

void LEDSub::SetRangeRGB(unsigned int start, unsigned int end, u_int8_t r, uint8_t g, uint8_t b)
{
    // Only index into allowed range
    if (start >= OperatorConstants::PIXEL_COUNT)
        return;

    // end must be after start and within valid range
    if (end <= start || end >= OperatorConstants::PIXEL_COUNT)
        return;

    for (int i = start; i <= end; i++)
    {
        m_PixelBuffer[i].SetRGB(r, g, b);
    }
}

void LEDSub::ApplyBuffer()
{
    m_AddressableLED.SetData(m_PixelBuffer);
}