#include "main.h"
#include "SETTINGS.hpp"
#include "pros/adi.hpp"
#include "pros/motors.h"

//Extra Motor Ports
pros::Motor Catapult1(_CatapultPort1, _CatapultGearset1);
pros::Motor Catapult2(_CatapultPort2, _CatapultGearset2);
pros::Motor intake1(_Intake1Port, _Intake1Gearset);
pros::Motor intake2(_Intake2Port , _Intake2Gearset);
pros::Motor roller(_RollerPort, _RollerGearset);

//ADI Ports
pros::ADIDigitalOut Intake_Actuate(_IntakeActuatorPort, _IntakeInitial);
pros::ADIDigitalIn limit_switch(_CatapultLimitSwitchPort);
pros::ADIDigitalOut Endgame(_EndgamePort, _EndgameInitial);

