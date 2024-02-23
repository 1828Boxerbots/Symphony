// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"
#include "commands/VisionAlignCmd.h"
#include "commands/AutoVisionShootCmd.h"
#include "commands/AutoBackupAndLoadToPhotoGateCmd.h"
#include "commands/AutoForwardCmd.h"
#include "commands/BatonSwingCmd.h"
#include "commands/ShootCmd.h"
#include "commands/AutoTurnCmd.h"

#include <frc2/command/Commands.h>
#include <frc2/command/SequentialCommandGroup.h>

frc2::CommandPtr autos::Position1CmdGrp(DriveSub* pDriveSub, LoaderSub *pLoaderSub, VisionSub *pVisionSub, ShooterSub *pShooterSub)
{
  // return frc2::SequentialCommandGroup(
  //   VisionAlignCmd(pVisionSub, pDriveSub, 0.5, 10.0)                            // look for AprilTag
  //   , AutoVisionShootCmd(pShooterSub, pVisionSub)                               // depending on vision distance, set shooter motor

  //   , AutoBackupAndLoadToPhotoGateCmd(pDriveSub, pLoaderSub, 2.0_m, 1.0, 1.0)   // backup to pick up next game-piece
  //   , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // move forward to get between 5.0_m and 10.0_m shooting range
  //   , VisionAlignCmd(pVisionSub, pDriveSub, 0.5, 10.0)                          // look for AprilTag
  //   , AutoVisionShootCmd(pShooterSub, pVisionSub)                               // depending on vision distance, set shooter motor

  //   , AutoForwardCmd(pDriveSub, -2.0_m, 1.0)                                    // backup to get out of starting area
  // ).ToPtr();
}

frc2::CommandPtr autos::Position2CmdGrp(DriveSub* pDriveSub, LoaderSub *pLoaderSub, VisionSub *pVisionSub, ShooterSub *pShooterSub, BatonSub *pBatonSub)
{
  // return frc2::SequentialCommandGroup(
  //   VisionAlignCmd(pVisionSub, pDriveSub, 0.5, 0)                               // look for AprilTag
  //   , BatonSwingCmd(true, pBatonSub)                                           // lift up baton
  //   , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot to baton
  //   , BatonSwingCmd(false, pBatonSub)                                           // drop baton

  //   // back out of shoot range
  //   , AutoForwardCmd(pDriveSub, 0.25_m, -1.0)                                   // backup

  //   // go towards next game-piece
  //   , AutoTurnCmd(pDriveSub, -90.0, 0.5)                                        // turn away, to get next note
  //   , AutoBackupAndLoadToPhotoGateCmd(pDriveSub, pLoaderSub, 2.0_m,1.0, 1.0)    // backup to pick up next game-piece

  //   // ------------------------------------------------------------------------
  //   // can we determine how far we went backwards to pick up game-piece ?
  //   // ------------------------------------------------------------------------
  //   , AutoForwardCmd(pDriveSub, 0.25_m, 1.0)                                    // backup
  //   , AutoTurnCmd(pDriveSub, +90.0, 0.5)                                        // turn towards amp
  //   // move fwards
  //   , AutoForwardCmd(pDriveSub, 0.25_m, 1.0)                                    // backup
  //   // 
  //   , BatonSwingCmd(true, pBatonSub)                                            // lift up baton
  //   , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot to baton
  //   , BatonSwingCmd(false, pBatonSub)                                           // drop baton
  // ).ToPtr();
}
