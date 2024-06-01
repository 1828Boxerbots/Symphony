#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/DriveSub.h"

class AutonomousPos3CmdGrp : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousPos3CmdGrp>
{
public:
    AutonomousPos3CmdGrp(DriveSub* drive);

private:
};