#include "commands/AutonomousPos2CmdGrp.h"

#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"

AutonomousPos2CmdGrp::AutonomousPos2CmdGrp(DriveSub* drive)
{
    AddCommands(
        AutoMoveForwardDistanceCmd(drive, 0.5, 45.83)
    );
}