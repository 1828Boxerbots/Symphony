#include "commands/AutonomousPos1CmdGrp.h"

#include "commands/Autonomous/AutoMoveForwardDistanceCmd.h"

AutonomousPos1CmdGrp::AutonomousPos1CmdGrp(DriveSub* drive)
{
    AddCommands(
        AutoMoveForwardDistanceCmd(drive, 0.5, 45.83)
    );
}