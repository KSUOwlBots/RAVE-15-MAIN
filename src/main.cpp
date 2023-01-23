#include "main.h"
#include "EZ-Template/util.hpp"
#include "Intakes.hpp"
#include "autons.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////

// Chassis constructor
Drive chassis(
    // Left Chassis Ports (negative port will reverse it!)
    //   the first port is the sensored port (when trackers are not used!)
    {20, 19, 18, -17}

    // Right Chassis Ports (negative port will reverse it!)
    //   the first port is the sensored port (when trackers are not used!)
    ,
    {-16,-15,14,-13}

    // IMU Port
    ,
    10

    // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
    //    (or tracking wheel diameter)
    ,
    2.75

    // Cartridge RPM
    //   (or tick per rotation if using tracking wheels)
    ,
    600

    // External Gear Ratio (MUST BE DECIMAL)
    //    (or gear ratio of tracking wheel)
    // eg. if your drive is 84:36 where the 36t is powered, your RATIO would
    // be 2.333. eg. if your drive is 36:60 where the 60t is powered, your RATIO
    // would be 0.6.
    ,
    1

    // Uncomment if using tracking wheels
    /*
    // Left Tracking Wheel Ports (negative port will reverse it!)
    // ,{1, 2} // 3 wire encoder
    // ,8 // Rotation sensor

    // Right Tracking Wheel Ports (negative port will reverse it!)
    // ,{-3, -4} // 3 wire encoder
    // ,-9 // Rotation sensor
    */

    // Uncomment if tracking wheels are plugged into a 3 wire expander
    // 3 Wire Port Expander Smart Port
    // ,1
);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::print_ez_template();

  pros::delay(
      500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(
      true); // Enables modifying the controller curve with buttons on the
             // joysticks
  chassis.set_active_brake(0.0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(
      .5, .5); // Defaults for curve. If using tank, only the first parameter is
             // used. (Comment this line out if you have an SD card!)
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants
                             // from autons.cpp!

  // These are already defaulted to these buttons, but you can change the
  // left/right curve but tons here! chassis.set_left_curve_buttons
  // (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If
  // using tank, only the left side is used.
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,
  // pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
      Auton("Rave Skills\n\nAuton for da skills, plz hit like how I hit your mom last night.", Rave_Skills),
      Auton("Rave Left\n\nLeft Side, Strong Side (I will love you if you know the reference).", Rave_Auto_Left),
      Auton("Rave Right\n\nIDK when I'm gonna make this s***. But still gonna be batter than Ayush's auton.", Rave_Auto_Right),
      Auton("Rave Left Full Send\n\n bust this sexy code out when shit gets funky.",Rave_Auto_Left_FullSend),
      Auton("Rave Right Full Send\n\n funky shit but for the right side,",Rave_Auto_Right_FullSend),
      Auton("Drive PID test\n\nTest code to tune drive pid.", Pid_Drive_Test),
      Auton("Turn PID Test\n\nTest code to tune turn pid. ", turn_example),
      /*Auton("Drive and Turn\n\nSlow down during drive.",
            wait_until_change_speed),
      Auton("Swing Example\n\nSwing, drive, swing.", swing_example),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently "
            "if interfered or not.",
            interfered_example),*/
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets();               // Resets PID targets to 0
  chassis.reset_gyro();                      // Reset gyro position to 0
  chassis.reset_drive_sensor();              // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps
                                             // autonomous consistency.

  //ez:as::auton_selector.call_selected_auton();

  Rave_Auto_Right();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {

  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  pros::Task Intakes(Intake_Control);
  pros::Task Roller(Roller_Control);
  pros::Task Catapult(Catapult_Control);
  pros::Task Endgame(Endgame_Fire); 
  

  while (true) {

    chassis.tank();
    //chassis.arcade_flipped(ez::SINGLE);
    pros::delay(ez::util::DELAY_TIME);

  }
}
