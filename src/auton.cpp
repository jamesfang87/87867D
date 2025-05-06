#include "auton.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/rtos.hpp"


ASSET(blueneg1_txt);
void blue_neg() {
    
}


ASSET(bluepos1_txt);
ASSET(bluepos2_txt);
void blue_pos() {
    //center goal rush
    chassis.setPose(55, -60, 90);
    chassis.follow(bluepos1_txt, 12, 1000, true, true);
    //2.46 - 1.56 = 0.9
    pros::delay(950);
    left_motors.brake();
    right_motors.brake();
    sweeper.toggle();

    // pull the mogo back
    chassis.moveToPoint(35, -60, 1000, {.forwards = false, .maxSpeed = 80}, false);
    sweeper.toggle();
    pros::delay(30);

    // grab goal
    chassis.turnToPoint(70, -60, 800, {}, true);
    chassis.moveToPoint(12, -55, 1000, {.forwards = false, .maxSpeed = 70}, false);
    pros::delay(80);
    clamp.toggle();
    pros::delay(40);
    
    // intake preload ring
    intake.move_velocity(400);
    // pros::delay(100);


    //grab other ring 
    chassis.turnToPoint(24, -48, 800, {.maxSpeed = 90}, true);
    intake.move_velocity(280);
    pros::delay(20);
    chassis.moveToPoint(25.5, -41.5, 1000, {.forwards = true, .maxSpeed = 50}, false);
    intake.brake();

    // drop the goal
    chassis.moveToPoint(50, -60, 1500, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    
    //grab second goal
    chassis.turnToPoint(70, -70, 800, {.maxSpeed = 90}, true);
    chassis.follow(bluepos2_txt, 12, 2200, false, false);
    pros::delay(20);
    clamp.toggle();
    pros::delay(20);
    intake.move_velocity(400);
    pros::delay(700);
    intake.brake();
    // clamp.toggle();

    // touch ladder
    chassis.turnToPoint(22, -12, 800, {.forwards = true, .maxSpeed = 90}, false);
    chassis.moveToPoint(22, -12, 1200, {.forwards = true, .maxSpeed = 62}, false);
    move_arm_to(170, 1500);

}


ASSET(redneg1_txt);
ASSET(redneg2_txt);
void red_neg() {
    // 239
    // alliance stake
    chassis.setPose(-60, 10, 210);
    move_arm_to(20, 1000);
    pros::delay(150);
    intake.move_velocity(400);
    pros::delay(350);
    intake.brake();
    move_arm_to(200, 1500);
    pros::delay(600);

    //mogo
    //chassis.moveToPoint(-56.1, 16.7, 1000, {.forwards = false, .minSpeed = 50}, false);
    //chassis.moveToPose(-23.5, 23.5, 300, 3000, {.forwards = false, .minSpeed = 5}, false);
    chassis.follow(redneg1_txt, 8, 2500, false, false);
    pros::delay(15);
    clamp.toggle();
    move_arm_to(0, 1500);

    // intake rings at line
    intake.move_velocity(525);
    chassis.turnToPoint(-9, 36.6, 600, {.earlyExitRange = 1}, false);
    chassis.moveToPoint(-9, 36.6, 800, {.minSpeed = 30, .earlyExitRange = 0.1}, false);
    left_motors.brake();
    right_motors.brake();

    chassis.turnToPoint(-8.3, 59.35, 600, {.maxSpeed = 100}, false);
    chassis.moveToPoint(-8.3, 59.35, 800, {.maxSpeed = 80}, false);
    
    //intake ring in middle of field
    chassis.moveToPose(-23.5, 23.5, 53, 2000, {.forwards = false, .minSpeed = 55}, false);
    chassis.turnToPoint(-23.5, 47, 600, {}, false);
    intake.move_velocity(400);
    chassis.moveToPoint(-23.5, 44, 800, {}, false);

    // corner bottom ring
    intake.brake();
    chassis.turnToPoint(-65, 65, 800, {}, false);
    intake.move_velocity(450);
    chassis.moveToPoint(-72, 72,1300, {.minSpeed = 20}, true);
    pros::delay(800);
    intake.brake();
    pros::delay(500);
    intake.move_velocity(500);
    chassis.moveToPoint(-55, 55, 700, {.forwards = false, .maxSpeed = 40}, false);
    pros::delay(50);

    // grab middle stacked ring
    intake.move_velocity(450);
    chassis.moveToPoint(-46, 3, 2000, {.maxSpeed = 67}, true);
    pros::delay(1000);
    intake_lift.toggle();
}


ASSET(redpos1_txt);
ASSET(redpos2_txt);
void red_pos() {
    //center goal rush
    chassis.setPose(-55, -60, 90);
    chassis.follow(redpos1_txt, 12, 1000, true, true);
    //2.46 - 1.56 = 0.9
    pros::delay(950);
    left_motors.brake();
    right_motors.brake();
    sweeper.toggle();

    // pull the mogo back
    chassis.moveToPoint(-35, -60, 1000, {.forwards = false, .maxSpeed = 80}, false);
    sweeper.toggle();
    pros::delay(30);

    // grab goal
    chassis.turnToPoint(-70, -60, 800, {}, true);
    chassis.moveToPoint(-12, -55, 1000, {.forwards = false, .maxSpeed = 70}, false);
    pros::delay(80);
    clamp.toggle();
    pros::delay(40);
    
    // intake preload ring
    intake.move_velocity(400);
    // pros::delay(100);

    // // go to corner
    // chassis.moveToPoint(-56, -56, 1200, {.minSpeed = 60}, false);
    // chassis.turnToPoint(-70, -70, 800, {.minSpeed = 70}, false);
    // chassis.moveToPoint(-70, -70, 1000, {.minSpeed = 80}, false);

    // // intake the bottom ring
    // intake.move_velocity(400);
    // chassis.moveToPoint(-67, -67, 1000, {.forwards = false, .minSpeed = 30}, false);
    
    //intake_lift.toggle();
    //chassis.moveToPoint(-70, -70, 800, {.minSpeed = 40}, false);

    

    //grab other ring 
    chassis.turnToPoint(-24, -48, 800, {.maxSpeed = 90}, true);
    intake.move_velocity(280);
    pros::delay(20);
    chassis.moveToPoint(-25.5, -41.5, 1000, {.forwards = true, .maxSpeed = 50}, false);
    intake.brake();

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
    // clamp.toggle();

    //hang
    // move_arm_to(300, 1500);
    // arm.brake();
    // chassis.turnToPoint(-9.5, -1.6, 800, {.forwards = false, .maxSpeed = 90}, false);
    // chassis.moveToPoint(-9.5, -1.6, 1200, {.forwards = false, .maxSpeed = 62}, false);
    // move_arm_to(0, 1500);
    // arm.brake(); 

    // touch ladder
    chassis.turnToPoint(-22, -12, 800, {.forwards = true, .maxSpeed = 90}, false);
    chassis.moveToPoint(-22, -12, 1200, {.forwards = true, .maxSpeed = 62}, false);
    move_arm_to(170, 1500);

}
 

void red_elim() {
    
}

void blue_elim() {
    
}