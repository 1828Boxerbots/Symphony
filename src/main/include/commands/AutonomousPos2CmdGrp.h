#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"
#include "subsystems/DriveSub.h"
#include "subsystems/VisionSub.h"
#include "subsystems/ShooterSub.h"
#include "subsystems/LoaderSub.h"

class AutonomousPos2CmdGrp : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutonomousPos2CmdGrp>
{
public:
    AutonomousPos2CmdGrp(DriveSub* drive, VisionSub* vision, ShooterSub* shooter, LoaderSub* loader);

private:
};