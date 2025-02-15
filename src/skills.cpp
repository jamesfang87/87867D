#include "skills.h"

ASSET(one_txt);

void skills() {
    // place to robot where back of the robot is right against
    // the black plastic holder for the alliance stake.
    // this distance (from the wall to the metal bar at the back of the robot) is 1.5 inches
    chassis.setPose(-60.5, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    intake.move_voltage(12000);
    pros::delay(500);
    intake.move_voltage(0);

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    chassis.moveToPoint(-46, 0, 500, {.minSpeed = 5});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-46, 22, 1000, {.forwards = false, .maxSpeed = 80}, false);
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);

    // get ring at (-24, 24)
    
    //pros::delay(1000);
    intake.move_voltage(12000);
    chassis.turnToHeading(90, 500);
    //intake.move_velocity(12000);
    //chassis.moveToPoint(-18, 22, 1000, {.minSpeed = 10});
    
    //pros::delay(1000);

    // get ring at (24, 47)
    chassis.follow(one_txt, 10, 4000);
}