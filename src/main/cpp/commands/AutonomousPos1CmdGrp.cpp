#include "commands/AutonomousPos1CmdGrp.h"

#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"
#include "commands/Autonomous/AutoRotateToAngleCmd.h"
#include "commands/AlignCmd.h"
#include "commands/Autonomous/AutoShootCmd.h"

AutonomousPos1CmdGrp::AutonomousPos1CmdGrp(DriveSub* drive, VisionSub* vision, ShooterSub* shooter, LoaderSub* loader)
{
    AddCommands(
        AutoMoveForwardDistanceCmd(drive, 0.5, 76.1),
        AutoRotateToAngleCmd(drive, 0.5, -135.0),
        AlignCmd(vision, drive, 0.25, 15.0),
        AutoShootCmd(shooter, loader),
        AutoRotateToAngleCmd(drive, 0.5, -180),
        AutoMoveForwardDistanceCmd(drive, -0.5, -24.9)
    );
}