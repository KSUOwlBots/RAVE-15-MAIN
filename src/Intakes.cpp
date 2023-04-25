#include "Intakes.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"
#include "SETTINGS.hpp"

void Intake_Control(void *) {
  while (true) {
    
    if ((master.get_digital(_OuttakeButton)) && (limit_switch.get_value() == 1)) {
      
         intake1.move_velocity(-600);
         
         intake2.move_velocity(600);
         
         Intake_Actuate.set_value(false);

       } else if ((master.get_digital(_IntakeButton)) && (limit_switch.get_value() == 1)) {
        
          Intake_Actuate.set_value(true);
      
          intake1.move_velocity(600);
       
          intake2.move_velocity(-600);

       } else {
      
       intake1.move_velocity(0);
      
       intake2.move_velocity(0);
       
       Intake_Actuate.set_value(false);
    
       }
  
    pros::delay(20);

  }

}

void Roller_Control(void *) {
  while (true) {
    if ((master.get_digital(_RollerButton))) {
      
      roller.move_velocity(-100);
    
    } else {

     roller.move_velocity(0);

    }
    
    pros::delay(20);
  
  }
 
 } 

void Intake_Auto(int x) {

  if((limit_switch.get_value() == 1)) {
   
   intake1.move_velocity(x);
   
   intake2.move_velocity(-x);
   
   Intake_Actuate.set_value(true);
   
  } else {
    
    intake1.move_velocity(0);
    
    intake2.move_velocity(0);
  
  }

}

void Intake_Match_Load(int x) {

if((limit_switch.get_value() == 1)) {
   
   intake1.move_velocity(x);
   
   intake2.move_velocity(-x);

} else {

   intake1.move_velocity(0);
   
   intake2.move_velocity(0);

}

}

void Intake_Toggle() {
       
  Intake_Actuate.set_value(false);

}


void Roller_Auto(int x) {
 
  roller.move_relative(x, 127);

}
