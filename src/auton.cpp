#include "auton.h"
#include "pros/rtos.hpp"



void blue_neg() {
    
}

ASSET(redneg1_txt);
void red_neg() {
    chassis.setPose(-63, 12, 270);
    chassis.follow(redneg1_txt, 12, 2500, false, false);
    clamp.toggle();
    pros::delay(100);

    intake.move_voltage(9500);
    chassis.turnToPoint(-9, 37, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-9, 37, 1000, {.maxSpeed = 70}, false);

    chassis.turnToPoint(-9, 44, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-9, 44, 1000, {.maxSpeed = 70}, false);

    chassis.moveToPoint(-11, 39, 1000, {.maxSpeed = 70}, false);

    chassis.moveToPoint(-24, 48, 1500, {.maxSpeed = 70}, false);
    intake_lift.toggle();

    //chassis.moveToPoint(-65, 65, 3000, {.maxSpeed = 70}, false);

    //chassis.moveToPoint(-48, 0, 3000, {.maxSpeed = 70}, false);
}

void red_elim() {
    

}

void blue_elim() {

}