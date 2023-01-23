#include "Intakes.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"

void Intake_Control(void *) {
  while (true) {
    
    if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) && (limit_switch.get_value() < 30)) {
      
         intake1.move_velocity(-600);
         
         intake2.move_velocity(600);
         
         Intake_Actuate.set_value(false);

       } else if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) && (limit_switch.get_value() < 30)) {
        
          Intake_Actuate.set_value(false);
      
          intake1.move_velocity(600);
       
          intake2.move_velocity(-600);

       } else {
      
       intake1.move_velocity(0);
      
       intake2.move_velocity(0);
       
       Intake_Actuate.set_value(true);
    
       }

    pros::delay(20);
  }
}

void Roller_Control(void *) {
  while (true) {
    if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))) {
      
      roller.move_velocity(100);
    
    } else if ((master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))) {

      roller.move_velocity(-100);

    } else {

     roller.move_velocity(0);

    }
    pros::delay(20);
  }
 } 

void Intake_Auto(int x) {

  if((limit_switch.get_value() < 30)) {
   
   intake1.move_velocity(x);
   
   intake2.move_velocity(-x);
   
   Intake_Actuate.set_value(false);
   
  } else {
    
    intake1.move_velocity(0);
    
    intake2.move_velocity(0);
  
  }
}

void Roller_Auto(int x) {
  roller.move_relative(x, 127);
}