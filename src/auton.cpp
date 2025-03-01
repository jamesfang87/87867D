#include "auton.h"
#include "pros/rtos.hpp"



void blue_neg() {
    
}

void blue_pos(){
    
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

ASSET(redpos1_txt);
ASSET(redpos2_txt);
ASSET(redpos3_txt);
void red_pos(){
    chassis.setPose(-63, -36, 270);
    chassis.follow(redpos1_txt, 12, 2500, false, false);
    clamp.toggle();
    pros::delay(60);
    intake.move_voltage(9500);
    pros::delay(100);
    clamp.toggle();

    chassis.turnToPoint(-23.5, -48, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-23.5, -48, 1000, {.maxSpeed = 70}, false);
    intake.move_voltage(4000);
    pros::delay(50);
    intake.break();
    
    chassis.follow(redpos2_txt, 12, 2500, false, false);
    clamp.toggle();
    // pros::delay(30);
    intake.move_voltage(9000);
    pros::delay(80);

    chassis.turnToPoint(-48, 0, 800, {.maxSpeed = 90}, false);
    intake.break();
    chassis.follow(redpos3_txt, 12, 3500, false, false);

}

void red_elim() {
    

}

void blue_elim() {

}