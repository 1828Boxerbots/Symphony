#include "commands/AutonomousPos2CmdGrp.h"

#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"
#include "commands/Autonomous/AutoRotateToAngleCmd.h"
#include "commands/AlignCmd.h"
#include "commands/Autonomous/AutoShootCmd.h"

AutonomousPos2CmdGrp::AutonomousPos2CmdGrp(DriveSub* drive, VisionSub* vision, ShooterSub* shooter, LoaderSub* loader)
{
    AddCommands(
        AutoMoveForwardDistanceCmd(drive, 0.5, 60.0),
        AutoRotateToAngleCmd(drive, 0.15, 135.0),
        AlignCmd(vision, drive, 0.25, 5.0),
        AutoShootCmd(shooter, loader),
        AutoRotateToAngleCmd(drive, 0.15, 360.0),
        AutoMoveForwardDistanceCmd(drive, 0.5, 40.0)
    );
}