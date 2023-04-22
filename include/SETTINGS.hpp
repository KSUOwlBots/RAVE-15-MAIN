#pragma once
#include "api.h"
#include "main.h"
using namespace pros;


// Auton
#define _SkillsAuton Rave_Skills()
#define _MatchAuton  Rave_Auto_Right()


// Controls
#define _DriveType chassis.tank()
#define _CatapultFire E_CONTROLLER_DIGITAL_L1

#define _RollerButton E_CONTROLLER_DIGITAL_L2

#define _IntakeButton E_CONTROLLER_DIGITAL_R1
#define _OuttakeButton E_CONTROLLER_DIGITAL_R2

#define _EndgameFireCombo1 E_CONTROLLER_DIGITAL_LEFT
#define _EndgameFireCombo2 E_CONTROLLER_DIGITAL_A


// Motors
#define _CatapultPort1 9
#define _CatapultGearset1 E_MOTOR_GEARSET_36
#define _CatapultPort2 8
#define _CatapultGearset2 E_MOTOR_GEARSET_36
#define _Intake1Port 12
#define _Intake1Gearset E_MOTOR_GEARSET_06
#define _Intake2Port 2
#define _Intake2Gearset E_MOTOR_GEARSET_06
#define _RollerPort 11
#define _RollerGearset E_MOTOR_GEARSET_36

// Pneumatics
#define _IntakeActuatorPort 'H'
#define _IntakeInitial true
#define _EndgamePort 'G'
#define _EndgameInitial false

// Sensors
#define _CatapultLimitSwitchPort 'B'
