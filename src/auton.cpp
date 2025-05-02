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
    //alliance stake
    chassis.setPose(-60, 10, 215);
    move_arm_to(20, 1000);
    arm.brake();
    pros::delay(150);
    intake.move_velocity(400);
    pros::delay(350);
    intake.brake();
    move_arm_to(250, 1500);
    arm.brake();
    pros::delay(600);

    //mogo
    chassis.follow(redneg1_txt, 12, 2500, false, false);
    clamp.toggle();
    move_arm_to(0, 1500);
    pros::delay(30);

    //ring 1
    chassis.turnToPoint(-22, 45, 800, {.maxSpeed = 90}, false);
    intake.move_velocity(400);
    chassis.moveToPoint(-22, 43, 1000, {.forwards = true, .maxSpeed = 70}, false);
    pros::delay(15);
    chassis.moveToPoint(-22, 36, 1000, {.forwards = false, .maxSpeed = 50}, false);

    //ring 2 and 3
    chassis.turnToPoint(-5, 38, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-5, 38, 1000, {.forwards = true, .maxSpeed = 50}, false);

    chassis.moveToPoint(-15, 40, 1000, {.forwards = false, .maxSpeed = 60}, false);

    chassis.turnToPoint(-3, 46, 800, {.maxSpeed = 90}, false);
    intake.move_velocity(400);
    chassis.moveToPoint(-3, 46, 1000, {.forwards = true, .maxSpeed = 50}, false);

    
}


ASSET(redpos1_txt);
ASSET(redpos2_txt);
void red_pos() {
    //center goal rush
    chassis.setPose(-55, -60, 90);
    chassis.follow(redpos1_txt, 12, 2000, true, true);

    pros::delay(1050);

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
    pros::delay(100);

    //grab other ring 
    chassis.turnToPoint(-24, -48, 800, {.maxSpeed = 90}, true);
    intake.move_velocity(280);
    pros::delay(20);
    chassis.moveToPoint(-25.5, -41.5, 1000, {.forwards = true, .maxSpeed = 50}, false);
    intake.brake();
    // chassis.moveToPoint(-24, -46, 900, {.forwards = false, .maxSpeed = 70}, false);

    // drop the goal
    chassis.moveToPoint(-50, -60, 1500, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    
    //grab second goal
    chassis.turnToPoint(-70, -70, 800, {.maxSpeed = 90}, true);
    chassis.follow(redpos2_txt, 12, 2200, false, false);
    pros::delay(20);
    clamp.toggle();
    pros::delay(20);
    intake.move_velocity(400);
    pros::delay(700);
    intake.brake();
    clamp.toggle();

    //hang
    move_arm_to(300, 1500);
    arm.brake();
    chassis.turnToPoint(0, 0, 800, {.forwards = false, .maxSpeed = 90}, false);
    chassis.moveToPoint(-7, -7, 1200, {.forwards = false, .maxSpeed = 62}, false);
    move_arm_to(0, 1500);
    arm.brake(); 

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