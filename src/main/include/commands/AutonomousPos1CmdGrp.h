#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/DriveSub.h"

class AutonomousPos1CmdGrp : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousPos1CmdGrp>
{
public:
    AutonomousPos1CmdGrp(DriveSub* drive);

private:
};