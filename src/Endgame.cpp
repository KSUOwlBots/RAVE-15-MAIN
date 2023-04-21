#include "Endgame.hpp"
#include "EZ-Template/sdcard.hpp"
#include "EZ-Template/util.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"
#include "EZ-Template\auton_selector.hpp"


void Endgame_Fire(void *)
{
  
  ///timer code
   double startTime, skillsTime, matchTime, deployTime, driveTime;
  
   bool wasDisabled = true;
   
   bool failSafe = false;

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
  
  ///////////

  while (true)
  {
    //fail safe code 
    if((pros::millis() - startTime >= deployTime) || (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))) {
    
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    master.set_text(0, 0, "Endgame go brrrrrrrr");
    
    failSafe = true;
  
  }

  //activates endgame use from timer or failsafe
  if (failSafe == true)
  {
    // SETTINGS.hpp > Controls > Endgame fire combo
    if (master.get_digital(_EndgameFireCombo1) && master.get_digital(_EndgameFireCombo2)) {
      
      Endgame.set_value(true);
      
      pros::Controller master(pros::E_CONTROLLER_MASTER);
      
      master.set_text(1, 0, "Endgame fire");
    
    } else {  
      
      Endgame.set_value(false);  
    
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
    Endgame.set_value(true);
  }
  else {
    Endgame.set_value(false);
  }
}
