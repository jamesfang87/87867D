#include "skills.h"
#include "pros/rtos.hpp"

ASSET(one_txt);
ASSET(two_txt);


void clamp_goal() {
    pros::delay(100);
    clamp.set_value(0);
    pros::delay(100);
}

void skills() {
    chassis.setPose(-63, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    intake.move_velocity(350);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    chassis.moveToPoint(-48, 0, 700, {}, false);
    chassis.turnToHeading(180, 700, {.maxSpeed = 40}, false);
    chassis.moveToPoint(-48, 20, 1000, {.forwards = false, .maxSpeed = 40}, false);
    //clamp_goal();
    //intake.move_velocity(350);
    chassis.moveToPoint(-23.5, 23.5, 3000, {.maxSpeed = 40}, false);
    // intake.brake();

    // chain this motion
    //chassis.moveToPoint(24, 48, 2000, {.maxSpeed = 80}, false);
    
    // get ring at (-24, 24) and (24, 48)
    // //intake.move_velocity(360);
    // chassis.turnToHeading(90, 700, {}, false);
    // chassis.follow(one_txt, 11, 4000, true, false);
    // pros::delay(75);

    // chassis.moveToPoint(0, 49.6, 1500, {.forwards = false, .maxSpeed = 60}, false);
    // chassis.turnToHeading(-90, 800, {.maxSpeed = 80}, false);

    // // intake the 3 collinear rings
    // //intake.move_velocity(300);
    // chassis.moveToPoint(-48, 48, 1250, {.maxSpeed = 43, .minSpeed = 27}, false);
    // //intake.move_velocity(400);
    // chassis.moveToPoint(-59, 48,1000, {.maxSpeed = 42, .minSpeed = 10}, false);
    // pros::delay(400);  // wait to intake ring
    // //intake.move_velocity(340);

    // chassis.moveToPoint(-44, 64, 1200, {.maxSpeed = 65}, false);
    // pros::delay(200);  // wait to intake ring

    // // put goal into corner
    // chassis.turnToPoint(-58, 65, 600, {.forwards = false, .maxSpeed = 95}, false);
    // chassis.moveToPoint(-58, 65, 1100, {.forwards = false, .maxSpeed = 70}, false);
    
    // pros::delay(100);
    // clamp.toggle();
    // intake.brake();
    // pros::delay(100);

    
    // chassis.moveToPoint(-47, 47, 1000 ,{.maxSpeed = 90}, false);
    // chassis.turnToHeading(0, 1500, {.maxSpeed = 90, .minSpeed = 20}, false);

    // chassis.moveToPoint(-47, 0, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 5,}, false);
    // chassis.moveToPoint(-47, -25, 1500, {.forwards = false, .maxSpeed = 55}, false);
    
    // clamp.toggle();
    // pros::delay(100);

    // // intake 2 rings, moving into position to intake the rest
    // intake.move_velocity(350);
    // chassis.follow(two_txt, 12, 3500, true, false);

    // chassis.moveToPoint(0, -47, 1000, {.forwards = false, .maxSpeed = 70}, false);
    // chassis.turnToHeading(270, 800, {.maxSpeed = 80}, false);

    // // intake the 3 collinear rings
    // intake.move_velocity(350);
    // chassis.moveToPoint(-48, -48, 1250, {.maxSpeed = 45, .minSpeed = 27}, false);
    // intake.move_velocity(400);
    // chassis.moveToPoint(-59, -48, 1000, {.maxSpeed = 42.5, .minSpeed = 10}, false);
    // pros::delay(400);  // wait to intake ring
    // intake.move_velocity(340);

    // chassis.moveToPoint(-44, -64, 2000, {.maxSpeed = 65}, false);
    // pros::delay(400);  // wait to intake ring

    // // put goal into corner
    // chassis.turnToPoint(-57, -65, 800, {.forwards = false, .maxSpeed = 80}, false);
    // chassis.moveToPoint(-57, -65, 1200, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // intake.brake();
    // pros::delay(200);
    
    // chassis.turnToPoint(60, -24, 700, {.forwards = true, .maxSpeed = 80}, false);
    // chassis.moveToPoint(34, -33, 2000, {.forwards = true, .maxSpeed = 90}, false);
    // chassis.moveToPoint(60, -24, 2000, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // pros::delay(200);

    // // put goal in corner
    // chassis.moveToPoint(66, -59, 1700, {.forwards = false, .maxSpeed = 80}, false);
    // clamp.toggle();
    // pros::delay(200);

    // // get into a more favorable position to clamp onto the middle mobile goal
    // chassis.moveToPoint(48, -24, 1500, {.maxSpeed = 70}, false);
    // // get the middle mogo and clamp
    // chassis.moveToPoint(48, 0, 1700, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // pros::delay(200);


    // // get the 6 rings left on the opposite side
    // intake.move_velocity(400);
    // chassis.moveToPoint(24, -24, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(0, 0, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(24, 24, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(24, 48, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(48, 48.5, 1800, {.maxSpeed = 70}, false);
    // intake.move_velocity(420);
    // chassis.moveToPoint(48, 64, 1700, {.maxSpeed = 70} ,false);
    
    // // put into corner
    // chassis.moveToPoint(59, 78, 2000, {.forwards = false, .maxSpeed = 90}, false);
    // clamp.toggle();
    // pros::delay(1200);

    // // HANGGGGGG!!!!!!!
    // intake.brake();
    // move_arm_to(700, 1500);
    // move_arm_to(0, 1500);
    // chassis.moveToPoint(24, 24, 2000, {.forwards = true, .maxSpeed = 70}, false);
    // move_arm_to(1500, 1500);
    // arm.brake();
    // chassis.moveToPoint(0, 0, 1500, {.forwards = false, .maxSpeed = 65}, false);
    // move_arm_to(0, 1500);
    // arm.brake();
    
}

void arm_test() {
    chassis.setPose(0, -48, 180);
    move_arm_to(250, 1000);
    intake.move_voltage(10000);
    chassis.moveToPoint(0, -65, 2000, {.maxSpeed = 70}, false);
    move_arm_to(2000, 2000);

}