#pragma once
#include "Catapult.hpp"
#include "Intakes.hpp"
#include "main.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;

void Rave_Auto_Left();
void Rave_Auto_Right();
void Rave_Auto_Left_FullSend();
void Rave_Auto_Right_FullSend();
void Rave_Skills();
void Pid_Drive_Test();
void turn_example();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void combining_movements();
void interfered_example();

void default_constants();
void one_mogo_constants();
void two_mogo_constants();
void exit_condition_defaults();
void modified_exit_condition();