#include "autons.hpp"
#include "api.h"
#include "main.h"
#include "pros/misc.h"
#include "EZ-Template/util.hpp"
#include "Catapult.cpp"
#include "ControllerPrinter.hpp"


void PrintInfo(void *) {

  pros::Imu imu_sensor(10);
  pros::Controller master (pros::E_CONTROLLER_MASTER);
  int count = 0;

    while (true) {

      if(!(count % 25)) {

        master.print(0, 0, "X-position of IMU: %f degrees\n", imu_sensor.get_heading());

        master.print(0, 0, "Z-position of IMU: %f degress\n", imu_sensor.get_rotation());

      }

     count++;
     pros::delay(25);

    }
}