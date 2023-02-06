#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

//Extra Motor Ports

pros::Motor Catapult(9, MOTOR_GEARSET_36);
pros::Motor intake1(12, MOTOR_GEARSET_6);
pros::Motor intake2(2 , MOTOR_GEARSET_6);
pros::Motor roller(11, MOTOR_GEARSET_36);

//ADI Ports
pros::ADIDigitalOut Intake_Actuate('H', true);
pros::ADIDigitalIn limit_switch('B');
pros::ADIDigitalOut Endgame('G', false);

