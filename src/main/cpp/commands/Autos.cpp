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

frc2::CommandPtr autos::Position1CmdGrp(DriveSub* pDriveSub, LoaderSub *pLoaderSub, VisionSub *pVisionSub, ShooterSub *pShooterSub, BatonSub *pBatonSub)
{

  return frc2::SequentialCommandGroup(

    //----------shooting into speaker-----------

    VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                            // will turn until it sees the speaker's AprilTag
    , AutoVisionShootCmd(pShooterSub, pVisionSub)                               // depending on vision distance, set shooter motor
    //Turn back the amount turned when aligning, will set it back straight.
    , AutoBackupAndLoadToPhotoGateCmd(pDriveSub, pLoaderSub, 2.0_m, 1.0, 1.0)   // backup to pick up next game-piece and cross line (disregard distance for now)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // move forward to line (disregard distance for now)
    , AutoTurnCmd(pDriveSub, +90.0, 0.5)                                        // turn towards amp (cw)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // scoot up to get inbto shooting range of amp (disregard distance for now)

    //----------shooting into amp---------------

    , VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                          // look for AprilTag
     , BatonSwingCmd(true, pBatonSub)                                           // lift up baton
    , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot into amp with baton
    , BatonSwingCmd(false, pBatonSub)                                           // drop baton

//end
  ).ToPtr();
}

frc2::CommandPtr autos::Position2CmdGrp(DriveSub* pDriveSub, LoaderSub *pLoaderSub, VisionSub *pVisionSub, ShooterSub *pShooterSub, BatonSub *pBatonSub)
{
  return frc2::SequentialCommandGroup(

     //----------shooting into speaker-----------


    VisionAlignCmd(pVisionSub, pDriveSub, 0.5 )                               // look for speaker's AprilTag
    , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot into speaker
    , AutoBackupAndLoadToPhotoGateCmd(pDriveSub, pLoaderSub, 2.0_m, 1.0, 1.0)   // backup to pick up next game-piece and cross line (disregard distance for now)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // move forward to line (disregard distance for now)


    //----------shooting into amp---------------

    , AutoTurnCmd(pDriveSub, +90.0, 0.5)                                        // turn towards amp (cw)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // move to get into shooting range of amp  (disregard distance for now)
    , VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                            // look for amp's AprilTag
    , BatonSwingCmd(true, pBatonSub)                                           // lift up baton
    , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot into amp with baton
    , BatonSwingCmd(false, pBatonSub)                                           // drop baton

//end
  ).ToPtr();
}


frc2::CommandPtr autos::Position3CmdGrp(DriveSub* pDriveSub, LoaderSub *pLoaderSub, VisionSub *pVisionSub, ShooterSub *pShooterSub, BatonSub *pBatonSub)
{
 return frc2::SequentialCommandGroup(


      VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                            // will turn until it sees the speaker's AprilTag
    , AutoVisionShootCmd(pShooterSub, pVisionSub)                               // depending on vision distance, set shooter motor
    //Turn back the amount turned when aligning, will set it back straight.
    , AutoBackupAndLoadToPhotoGateCmd(pDriveSub, pLoaderSub, 2.0_m, 1.0, 1.0)   // backup to pick up next game-piece and cross line (disregard distance for now)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // move forward to line (disregard distance for now)
    , AutoTurnCmd(pDriveSub, +90.0, 0.5)                                        // turn towards amp (cw)
    , AutoForwardCmd(pDriveSub, 1.0_m, 1.0)                                     // Move more than pos 1 to get into shooting range of amp (disregard distance for now)

    //----------shooting into amp---------------

    , VisionAlignCmd(pVisionSub, pDriveSub, 0.5)                          // look for AprilTag
     , BatonSwingCmd(true, pBatonSub)                                           // lift up baton
    , ShootCmd(pShooterSub, pVisionSub, 1.0)                                    // shoot into amp with baton
    , BatonSwingCmd(false, pBatonSub)                                           // drop baton
 
 //end


 ).ToPtr();
}

