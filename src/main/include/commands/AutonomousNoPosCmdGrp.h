#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"

class AutonomousNoPosCmdGrp : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousNoPosCmdGrp>
{
public:
    AutonomousNoPosCmdGrp();

private:
};