#include "Catapult.hpp"
#include "Intakes.hpp"
#include "Endgame.hpp"
#include "main.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

/////s
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////

const int DRIVE_SPEED =
    80; // This is 110/127 (around 87% of max speed).  We don't suggest making
        // this 127. If this is 127 and the robot tries to heading correct, it's
        // only correcting by making one side slower.  When this is 87%, it's
        // correcting by making one side faster and one side slower, giving
        // better heading correction.
const int TURN_SPEED = 60;
const int SWING_SPEED = 90;

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier
// game objects, or with lifts up vs down. If the objects are light or the cog
// doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void waitForRoller()
{
  while (!roller.is_stopped()) {
    pros::delay(20);
  }
}

   // PID TEST AUTOS //
////////////////////////////

void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}

void Pid_Drive_Test() {

  pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

  chassis.set_drive_pid(64, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-64, DRIVE_SPEED);
  chassis.wait_drive();

  pros::delay(500);
}

 // RAVE AUTOS //
/////////////////////////////

  /*
  **  | |\ \      / /| |                 | |                | |
  **  | | \ \    / / | |             ____| |____            | |  
  **  | |  \ \  / /  | |            |____   ____|           | |  _____
  **  | |   \ \/ /   | |     /    \      | |      /  ___|   | | / ___ \
  **  | |    \__/    | |    /  ^   \     | |     /  /       | |/ /   \ \
  **  | |            | |   / /__\ ^ \    | |     \  \___    |   /    | |
  **  |_|            |_|   \_____/ \_\   |_|      \_____|   |__|     |_|
  */

 /*void Rave_Auto_Right() {

  pros::Task Catapult(Catapult_Down);

  Intake_Auto(100);

  chassis.set_drive_pid(-34, 75);
  chassis.wait_drive();

  Intake_Auto(0);

  pros::delay(150);

  chassis.set_turn_pid(-140, 75);
  chassis.wait_drive();

  pros::delay(150);

  chassis.set_drive_pid(4, 75);
  chassis.wait_drive();
  
  Catapult_Fire();

  pros::delay(500);

  chassis.set_drive_pid(-4, 35);
  chassis.wait_drive();

  pros::delay(1500);

  Intake_Auto(600);

  chassis.set_turn_pid(55, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-6, 35);
  chassis.wait_drive();

  chassis.set_drive_pid(6, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(-143, 75);
  chassis.wait_drive();

  pros::delay(150);

  chassis.set_drive_pid(8, 75);
  chassis.wait_drive();

  Catapult_Fire();

  pros::delay(500);

  chassis.set_drive_pid(-10, 35);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, 75);
  chassis.wait_drive();

  pros::delay(500);

  chassis.set_drive_pid(-12, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(16, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(-143, 75);
  chassis.wait_drive();

  pros::delay(175);

  chassis.set_drive_pid(8, 75);
  chassis.wait_drive();

  Catapult_Fire();

  pros::delay(250);

  chassis.set_turn_pid(-124, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, 75);
  chassis.wait_drive();


}*/

void Rave_Auto_Right() {

 pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

 

   /////// FIRST CATA SHOT //////////

   Intake_Auto(100);

   chassis.set_drive_pid(-20, 75);
   chassis.wait_drive();

   Intake_Auto(0);

   chassis.set_turn_pid(-154, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(8, 30);
   chassis.wait_drive();
  
   pros::delay(150);

   Catapult_Fire();

   pros::delay(2000);

  /////////////

  ////// SECOND CATA SHOT ///////

   Intake_Auto(600);

   chassis.set_drive_pid(-8, 45);
   chassis.wait_drive();

   chassis.set_turn_pid(45, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(-10, 55);
   chassis.wait_drive();

   chassis.set_drive_pid(6, 55);
   chassis.wait_drive();

   chassis.set_turn_pid(-154, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(4, 30);
   chassis.wait_drive();

   pros::delay(150);

   Catapult_Fire();

   pros::delay(500);
   

  //////////

 /// THIRD CATA SHOT //////////

   chassis.set_drive_pid(-8, 55);
   chassis.wait_drive();

   chassis.set_turn_pid(-45, 55);
   chassis.wait_drive();

   chassis.set_drive_pid(-36, 55);
   chassis.wait_drive();

   chassis.set_turn_pid(-135, 55);
   chassis.wait_drive();

   chassis.set_drive_pid(2,30);
   chassis.wait_drive();

   pros::delay(150);

   Catapult_Fire();

   pros::delay(500);

  ///////////////

 /// FOURTH CATA SHOT//////////

   chassis.set_drive_pid(-5, 30);
   chassis.wait_drive();

   chassis.set_swing_pid(ez::LEFT_SWING, -178, 55);
   chassis.wait_drive();

   chassis.set_drive_pid(-17, 30);
   chassis.wait_drive();

   chassis.set_drive_pid(17, 75);
   chassis.wait_drive();

   chassis.set_turn_pid(-135,65);
   chassis.wait_drive();

   chassis.set_drive_pid(12, 30);
   chassis.wait_drive();

   pros::delay(150);
  
   Catapult_Fire();

   pros::delay(500);

  //////////////////////////

  //// ROLLER ///////

    Intake_Auto(0);

   chassis.set_drive_pid(-6, 50);
   chassis.wait_drive();

   chassis.set_turn_pid(-45, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(48, 75);
   chassis.wait_drive();

   chassis.set_turn_pid(125, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(-20, 55);
   chassis.wait_drive();

   chassis.set_turn_pid(180, 65);
   chassis.wait_drive();

   chassis.set_drive_pid(-20, 30);
   chassis.wait_drive();

   Roller_Auto(-450);

   pros::delay(500);

  //Go for disc on low goal barrier

  chassis.set_drive_pid(10, 50);
  chassis.wait_drive();

  chassis.set_turn_pid(280, 65);
  chassis.wait_drive();

  Intake_Auto(600);

  chassis.set_drive_pid(-56, 75, true);
  chassis.wait_drive();

  chassis.set_drive_pid(4, 30);
  chassis.wait_drive();

  //Go for disc on line

  chassis.set_turn_pid(33, 65);
  chassis.wait_drive();

  chassis.set_drive_pid(-34, 75, true);
  chassis.wait_drive();

  //Aim at goal and fire

  chassis.set_drive_pid(6, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(216, 65);
  chassis.wait_drive();

  pros::delay(150);
  Catapult_Fire();
  pros::delay(500);

  Catapult.remove();

  //Go for discs on barrier

  /*chassis.set_turn_pid(275, 65);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, 40);
  chassis.wait_drive();

  chassis.set_drive_pid(40, 75, true);
  chassis.wait_drive();

  //Fire at goal

  chassis.set_turn_pid(216, 65);
  chassis.wait_drive();

  pros::delay(150);
  Catapult_Fire();
  pros::delay(500);
  
  Catapult.remove();
  */

  ////////////////////
}


void Rave_Auto_Left() {

  pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

  Intake_Auto(10);

  chassis.set_drive_pid(-48, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 60);
  chassis.wait_drive();

  chassis.set_turn_pid(36000, TURN_SPEED);

  chassis.set_drive_pid(3, 20, false);
  chassis.wait_drive();

  pros::delay(250);

  Catapult_Fire();

  pros::delay(1500);

  Intake_Auto(-600);

  pros::delay(50);

  Intake_Auto(600);

  chassis.set_turn_pid(145, 60);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, 20, false);
  chassis.wait_drive();

  chassis.set_drive_pid(20, 20, false);
  chassis.wait_drive();

  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(250);

  Catapult_Fire();

  pros::delay(1500);

  chassis.set_drive_pid(-12, 40, false);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 175, 40);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 50, false);
  chassis.wait_drive();

  chassis.set_drive_pid(30, 75, false);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, 135, 40);
  chassis.wait_drive();

  chassis.set_drive_pid(12, 40, false);
  chassis.wait_drive();

  pros::delay(250);

  Catapult_Fire();

  pros::delay(1500);

  chassis.set_drive_pid(-6, 40, false);
  chassis.wait_drive();

  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, DRIVE_SPEED, false);
  chassis.wait_drive();

  pros::delay(250);

  chassis.set_drive_pid(-12, 40, false);
  chassis.wait_drive();

  chassis.set_drive_pid(52, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 60);
  chassis.wait_drive();

  chassis.set_drive_pid(6, 40, false);
  chassis.wait_drive();

  pros::delay(250);

  Catapult_Fire();

  pros::delay(1500);
}

void Rave_Auto_Left_FullSend() {

pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

Intake_Auto(10); 

}

void Rave_Auto_Right_FullSend() {

pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

Intake_Auto(10); 

}


/*
**     / ____|  | |      (_)  | |  | | 
**    | (___    | | __    __  | |  | |   ____
**     \___ \   | |/ /   | |  | |  | |  / __|
**     ____) |  |   <    | |  | |  | |  \__ \
**    |_____/   |_|\_\   |_|  |_|  |_|  |___/
*/

void Rave_Skills()
{
  pros::Task Catapult(Catapult_Down); // Cata Reloads Constantly

  //Spin Roller
  chassis.set_drive_pid(-2, 30);
  chassis.wait_drive();

  Roller_Auto(900);
  pros::delay(1000);

  //Go for 1 disc
  Intake_Auto(600);

  chassis.set_drive_pid(6, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(135, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-18, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(90, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, 30);
  chassis.wait_drive();

  //Spin Roller
  Roller_Auto(900);
  pros::delay(1000);

  //Go for goal

  chassis.set_drive_pid(4, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(0, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(62, 75, true);
  chassis.wait_drive();

  chassis.set_turn_pid(15, 75);
  chassis.wait_drive();

  //Fire cata
  pros::delay(250);
  Catapult_Fire();
  pros::delay(500);

  //Go for 3 line

  chassis.set_turn_pid(0, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-28, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-28, 75);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-31, 50);
  chassis.wait_drive();

  //Aim at goal and fire

  chassis.set_turn_pid(-45, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(6, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(-50, 30);
  chassis.wait_drive();

  pros::delay(250);
  Catapult_Fire();

  pros::delay(500);

  //Go to triple stack

  chassis.set_turn_pid(-45 , 30);
  chassis.wait_drive();

  chassis.set_drive_pid(-10, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(-135, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-48, 25);
  chassis.wait_drive();

  chassis.set_drive_pid(48, 75, true);
  chassis.wait_drive();

  //Ain at goal and fire

  chassis.set_turn_pid(-45, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(10, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(-50, 30);
  chassis.wait_drive();

  pros::delay(250);
  Catapult_Fire();

  pros::delay(500);

  //Get 3 discs along barrier

  chassis.set_drive_pid(-8, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(95, 60);
  chassis.wait_drive();

  chassis.set_drive_pid(-52, 30);
  chassis.wait_drive();

  //Aim at goal and fire

  chassis.set_turn_pid(15, 75);
  chassis.wait_drive();

  pros::delay(250);
  Catapult_Fire();

  pros::delay(500);

  //Go for other 3 stack

  chassis.set_turn_pid(-20, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-48, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, 30);
  chassis.wait_drive();

  //Aim at other goal and fire

  chassis.set_turn_pid(95, 75);
  chassis.wait_drive();

  chassis.set_drive_pid(50 , 75, true);
  chassis.wait_drive();

  chassis.set_turn_pid(80, 30);
  chassis.wait_drive();

  pros::delay(250);
  Catapult_Fire();

  pros::delay(500);

  //Do three line on low goal

  chassis.set_drive_pid(-5, 30);
  chassis.wait_drive();

  chassis.set_turn_pid(185, 50);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, 30);
  chassis.wait_drive();

  //Aim at goal and fire

  chassis.set_turn_pid(135, 75);
  chassis.wait_drive();

  pros::delay(250);
  Catapult_Fire();

  pros::delay(500); 
}

///
// Turn Example
///
/*void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}*/

///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}

///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining
  // distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot
                             // will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining
  // distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot
                             // will go the remaining distance at 40 speed
  chassis.wait_drive();
}

///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}

///
// Interference example
///
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
}
