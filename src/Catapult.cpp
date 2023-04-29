#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

bool firing;


void Catapult_Control(void *) {
  while (true) {
    
    Catapult1.move_velocity(100);
    
    Catapult2.move_velocity(100);

    if (limit_switch.get_value() == 1) {
    
      Catapult1.move_velocity(0);
    
      Catapult2.move_velocity(0);
    
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      
      Catapult1.move_velocity(100);
    
      Catapult2.move_velocity(100);
      
      pros::delay(250);
      
      Catapult1.tare_position();
    
      Catapult2.tare_position();
      
    }

    pros::delay(20);
 
  }

}
 

void Catapult_Down(void *) {

  while (true) {

    if (firing) {

      Catapult1.move_velocity(100);

      Catapult2.move_velocity(100);
      
      pros::delay(300);
      
      Catapult1.tare_position();
      
      Catapult2.tare_position();
      
      firing = false;
    
    } else {
      
      Catapult1.move_velocity((-0.0135135135*Catapult1.get_position() + 100));
      
      Catapult2.move_velocity((-0.0135135135*Catapult2.get_position() + 100));

      if (limit_switch.get_value() == 1) {
      
        Catapult1.move_velocity(0);
      
        Catapult2.move_velocity(0);
      
      }
    
    }

    pros::delay(20);
  
  }

}

void Catapult_Fire(void) {
  firing = true;
}

void BoostOff(void *) {

 while(true) {

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {

    BoosterShot.set_value(true);

  }

 }
  
}
