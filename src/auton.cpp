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

void blue_pos(){
    
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
void red_pos() {
    chassis.setPose(-63, -36, 270);
    chassis.follow(redpos1_txt, 12, 3000, false, false);
    clamp.toggle();

    intake.move_velocity(400);
    pros::delay(1000);
    chassis.moveToPoint(-24, -48, 3000, {.maxSpeed = 50}, false);
    intake.brake();
    chassis.moveToPoint(-11, -27, 3000, {.maxSpeed = 60}, false);
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
    blue_pos();
}