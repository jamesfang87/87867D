#include "auton.h"
#include "pros/rtos.hpp"


ASSET(blueneg1_txt);
void blue_neg() {
    chassis.setPose(63, 12, 90);
    chassis.follow(blueneg1_txt, 12, 2500, false, false);
    clamp.toggle();

    intake.move_velocity(350);
    pros::delay(1000);
    
    intake.move_velocity(400);
    chassis.turnToPoint(9.7, 37, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(9.7, 37, 1400, {.maxSpeed = 65}, false);

    intake.move_velocity(350);
    chassis.turnToPoint(8.5, 47, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(8.5, 47, 1400, {.maxSpeed = 65}, false);

    chassis.moveToPoint(11, 30, 2000, {. forwards = false, .maxSpeed = 70}, false);
    intake.move_velocity(350);
    chassis.moveToPoint(25, 48, 2000, {.maxSpeed = 70, .minSpeed = 30}, false);
    pros::delay(1000);
    intake_lift.toggle();

    chassis.moveToPoint(35.5, 23.5, 2000, {.maxSpeed = 70, .minSpeed = 20}, false);
    chassis.moveToPoint(48, 0,  2000, {.maxSpeed = 45}, false);
}

ASSET(redneg1_txt);
void red_neg() {
    chassis.setPose(-63, 12, 270);
    chassis.follow(redneg1_txt, 12, 2500, false, false);
    clamp.toggle();

    intake.move_velocity(350);
    pros::delay(1000);
    
    intake.move_velocity(400);
    chassis.turnToPoint(-9.7, 37, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-9.7, 37, 1400, {.maxSpeed = 65}, false);

    intake.move_velocity(350);
    chassis.turnToPoint(-8.5, 47, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-8.5, 47, 1400, {.maxSpeed = 65}, false);

    chassis.moveToPoint(-11, 30, 2000, {. forwards = false, .maxSpeed = 70}, false);
    intake.move_velocity(350);
    chassis.moveToPoint(-25, 48, 2000, {.maxSpeed = 70, .minSpeed = 30}, false);
    pros::delay(1000);
    intake_lift.toggle();

    chassis.moveToPoint(-35.5, 23.5, 2000, {.maxSpeed = 70, .minSpeed = 20}, false);
    chassis.moveToPoint(-48, 0,  2000, {.maxSpeed = 50, .minSpeed = 10}, false);
}


ASSET(redpos1_txt);
ASSET(redpos2_txt);
void red_pos() {
    //center goal rush
    chassis.setPose(-55, -60, 90);
    chassis.follow(redpos1_txt, 12, 2000, true, true);

    pros::delay(900);

    sweeper.toggle();
    // pros::delay(50);

    chassis.moveToPoint(-35, -60, 1000, {.forwards = false, .maxSpeed = 80}, false);
    sweeper.toggle();
    pros::delay(30);

    chassis.turnToPoint(-70, -70, 800, {.maxSpeed = 90}, true);
    chassis.moveToPoint(-15, -58, 1000, {.forwards = false, .maxSpeed = 60}, false);
    pros::delay(80);
    clamp.toggle();
    pros::delay(40);
    

    intake.move_velocity(400);
    pros::delay(120);

    //grab other ring (not tested)
    chassis.turnToPoint(-10, -48, 800, {.maxSpeed = 90}, true);
    intake.move_velocity(90);
    chassis.moveToPoint(-10, -46, {.forwards = true, .maxSpeed = 50}, false);
    intake.brake();

    // drop the goal
    chassis.moveToPoint(-50, -60, 2000, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    
    
    //grab second goal
    // chassis.moveToPoint(-40, -60, 2000, {.forwards = true, .maxSpeed = 70}, false);
    chassis.turnToPoint(-70, -70, 800, {.maxSpeed = 90}, true);
    chassis.follow(redpos2_txt, 12, 2000, false, false);
    clamp.toggle();

    // clamp.toggle();
}


ASSET(bluepos1_txt);
void blue_pos() {
    chassis.setPose(63, -36, 90);
    chassis.follow(bluepos1_txt, 12, 3000, false, false);
    clamp.toggle();

    intake.move_velocity(400);
    pros::delay(1000);
    chassis.moveToPoint(24, -48, 3000, {.maxSpeed = 50}, false);
    intake.brake();

    
    chassis.moveToPoint(11, -27, 3000, {.maxSpeed = 60}, false);
}


ASSET(blueelim1_txt);
void test() {
    chassis.follow(blueelim1_txt, 12, 2000, false, false);
    intake.move_velocity(400);
    pros::delay(1000);

    chassis.moveToPoint(24, -36, 1500, {.forwards = false, .maxSpeed = 85, .minSpeed = 20}, false);
    chassis.moveToPoint(10, -42.5, 1500, {.forwards = false, .maxSpeed = 50}, false);
    clamp.toggle();



    chassis.moveToPoint(24, -36, 1500, {.forwards = false, .maxSpeed = 65, .minSpeed = 20}, false);
    chassis.moveToPoint(24, -48, 3000, {.forwards = false, .maxSpeed = 50}, false);
    
    
    intake.brake();
    //chassis.moveToPoint(11, -27, 3000, {.maxSpeed = 60}, false);
}

void red_elim() {
    
}

void blue_elim() {
    blue_pos();
}