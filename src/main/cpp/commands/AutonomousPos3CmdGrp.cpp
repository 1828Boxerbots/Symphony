#include "commands/AutonomousPos3CmdGrp.h"

#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"

AutonomousPos3CmdGrp::AutonomousPos3CmdGrp(DriveSub* drive)
{
    AddCommands(
        AutoMoveForwardDistanceCmd(drive, 0.5, 101.595)
    );
}