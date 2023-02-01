#include "Endgame.hpp"
#include "EZ-Template/sdcard.hpp"
#include "EZ-Template/util.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"
#include "EZ-Template\auton_selector.hpp"


void Endgame_Fire(void *)
{

   double startTime, skillsTime, matchTime, deployTime, driveTime;
    bool wasDisabled = true;

    if(wasDisabled) {
      startTime = pros::millis();
    }

     matchTime = 75;
     skillsTime = 60;

     if(ez::as::auton_selector.current_auton_page == 1) {
      driveTime = skillsTime;
     }

     if(ez::as::auton_selector.current_auton_page == 3) {
      driveTime = matchTime;
     }

     deployTime = driveTime*1000 - 10000;
  
  while (true)
  {

   if(pros::millis()- startTime >= deployTime) {

   pros:: Controller master(pros::E_CONTROLLER_MASTER);

   master.set_text( 0, 0, "Raze Nade");
     
     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    
    {
      Endgame.set_value(false);
    
    } else {
    
      Endgame.set_value(true);
    
    }

    pros::delay(20);
   }


    /*if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
    {
      Endgame.set_value(false);
    }
    else {
      Endgame.set_value(true);
    }

    pros::delay(20);
  }*/
}
}

void Endgame_fire_Auto(int x) {
      
  if (x == 1)
  {
    Endgame.set_value(false);
  }
  else {
    Endgame.set_value(true);
  }
}

