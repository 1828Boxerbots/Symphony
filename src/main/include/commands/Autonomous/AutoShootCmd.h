#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

#include "subsystems/ShooterSub.h"
#include "subsystems/LoaderSub.h"

class AutoShootCmd : public frc2::CommandHelper<frc2::Command, AutoShootCmd>
{
public:
    AutoShootCmd(ShooterSub* shooter, LoaderSub* loader);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    ShooterSub* m_pShooterSub = nullptr;
    LoaderSub* m_pLoaderSub = nullptr;
    
    bool m_IsFinished = false;
};