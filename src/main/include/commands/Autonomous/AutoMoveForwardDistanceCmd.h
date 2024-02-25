#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

#include "subsystems/DriveSub.h"

class AutoMoveForwardDistanceCmd : public frc2::CommandHelper<frc2::Command, AutoMoveForwardDistanceCmd>
{
public:
    AutoMoveForwardDistanceCmd(DriveSub* sub, double speed, double dist);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSub* m_pDriveSub = nullptr;
    double m_Speed;
    double m_Distance;
    
    bool m_IsFinished = false;
};