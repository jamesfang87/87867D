#include "skills.h"

ASSET(one_txt);
ASSET(two_txt);
ASSET(three_txt);
ASSET(four_txt);
ASSET(five_txt);
ASSET(six_txt);

// probably good
void high_stake1() {
    // place to robot where back of the robot is right against
    // the black plastic holder for the alliance stake.
    // this distance (from the wall to the metal bar at the back of the robot) is 1.5 inches
    // the preload should be about in the middle
    chassis.setPose(-60.5, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    intake.move_voltage(12000);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    // inconsistent, fluctuates most with battery %
    chassis.moveToPoint(-44, 0, 500);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-49, 24, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 10}, false);
    
    // clamp goal
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);

    // get ring at (-24, 24) and (24, 48)
    intake.move_voltage(12000);
    chassis.turnToHeading(90, 500, {}, false);
    // TODO: test this after imu is moved
    chassis.follow(one_txt, 11, 3500, true, false);
    pros::delay(75);

    // TODO: test this after imu is moved
    chassis.moveToPoint(0, 49.6, 1200, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(-90, 750, {.maxSpeed = 80}, false);
}

/**
 * Ran after scoring on the left wall stake (viewed from starting side)
 */
void corner1() {
    chassis.setPose(0, 48, 270); // do not remove
    imu.set_heading(270);

    // intake the 3 collinear rings
    intake.move_voltage(12000);
    chassis.moveToPoint(-59, 48, 2750, {.maxSpeed = 50, .minSpeed = 10}, false);
    pros::delay(600);  // wait to intake ring

    chassis.moveToPoint(-44, 61, 2000, {.maxSpeed = 60}, false);
    pros::delay(400);  // wait to intake ring

    // put goal into corner
    chassis.moveToPoint(-61, 61, 2000, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    intake.brake();

    pros::delay(100);
    chassis.setPose(chassis.getPose().x, chassis.getPose().y, 140);
    
    // prepare to move to the bottom corner
    // !this does not move to bottom corner, only prepares to
    chassis.moveToPoint(-47, 47, 1000);
    chassis.turnToHeading(0, 500, {.maxSpeed = 80});
}

void corner2() {
    chassis.setPose(-47, 47, 0); // TODO: test theta that we set to

    // get mobile goal; note: clamp is open at this point
    chassis.moveToPoint(-47, -25, 2000, {.forwards = false, .maxSpeed = 100, .earlyExitRange = 35}, false);
    clamp.toggle();
    pros::delay(100);

    // intake 2 rings, moving into position to intake the rest
    intake.move_voltage(12000);
    chassis.follow(two_txt, 12, 3000, true, false);

    chassis.moveToPoint(0, -49.5, 2000, {.forwards = false, .maxSpeed = 60}, false);

    // intake 3 collinear rings
    chassis.moveToPoint(-59, -48, 2000, {.maxSpeed = 60, .minSpeed = 10}, false);
    pros::delay(600);
    chassis.moveToPoint(-44, -61, 1500, {.maxSpeed = 60}, false);
    pros::delay(400);

    // put goal in corner
    chassis.moveToPoint(-61, -61, 1000, {.forwards = false}, false);
    clamp.toggle();
    intake.brake();

    pros::delay(100);
    chassis.setPose(chassis.getPose().x, chassis.getPose().y, 140);
}

void third_goal() {
    chassis.moveToPoint(60, -24, 3000, {.forwards = false, .earlyExitRange = 7.5}, false);
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);


    move_arm_to(200.0, 1000);
    intake.move_voltage(12000);

    chassis.moveToPoint(59, -44, 1000, {.maxSpeed = 60}, false);
    // put goal in corner
    chassis.moveToPoint(68.504, -61, 1000, {.forwards = false}, false);
    clamp.toggle();
    
    chassis.moveToPoint(47, 0, 1500, {.forwards = false, .maxSpeed = 60, .earlyExitRange = 10}, false);
    move_arm_to(500, 1000);
    chassis.turnToHeading(90, 1000, {}, false);

    chassis.turnToHeading(226, 1000, {}, false);

    intake.move_voltage(12000);
    chassis.follow(six_txt, 18, 6000, true, false);
}


void skills() {
    high_stake1();
    corner1();
    corner2();

}