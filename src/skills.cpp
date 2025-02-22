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
    //intake.move_voltage(12000);
    pros::delay(500);
    //intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    // inconsistent, flucuates most with battery %
    chassis.moveToPoint(-44, 0, 500);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-49, 24, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 10}, false);
    
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);

    // get ring at (-24, 24) and (24, 48)
    //intake.move_voltage(12000);
    chassis.turnToHeading(90, 500, {}, false);
    chassis.follow(one_txt, 14, 6100, true, false);
    pros::delay(100);

    // it gets off, that's why i set to 3 here
    chassis.moveToPoint(3, 46.5, 2000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(270, 1500, {.maxSpeed = 50}, false);
    pros::delay(200);

    clamp.toggle();
}

/**
 * Ran after scoring on the left wall stake (viewed from starting side)
 */
void corner1() {
    chassis.setPose(0, 47, 270); // do not remove
    imu.set_heading(270);

    // turn to face rings
    //intake.move_voltage(12000);

    //intake_lift.toggle();

    chassis.moveToPoint(-64, 47, 2000, {.maxSpeed = 55, .minSpeed = 10}, false);
    pros::delay(200);
    //intake_lift.toggle();
    chassis.moveToPoint(-56, 47, 500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.follow(two_txt, 10, 2500, true, false);

    // put goal into corner
    chassis.moveToPoint(-64, 64, 1000, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    //intake.move_voltage(-12000);

    pros::delay(10000);

    // chassis.moveToPoint(-47, 47, 1000, {}, false);
    // chassis.turnToHeading(0, 2000, {}, false);

    // note: this does not move to bottom corner
}

void corner2() {
    chassis.setPose(-47, 47, 0);

    // clamp is open at this point
    chassis.moveToPoint(-47, -25, 3000, {.forwards = false, .maxSpeed = 100}, false);
    clamp.toggle();
    pros::delay(100);

    //intake.move_voltage(12000);
    chassis.follow(four_txt, 12, 3000, true, false);

    chassis.moveToPoint(-64, -47, 2000, {.maxSpeed = 60, .minSpeed = 10}, false);
    pros::delay(200);

    chassis.moveToPoint(-56, -48, 500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.follow(five_txt, 10, 2500, true, false);

    // put goal in corner
    chassis.moveToPoint(-64.32, -65.6, 1000, {.forwards = false}, false);
    clamp.toggle();
}

void third_goal() {
    chassis.setPose(0, -48, 180);

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
    //corner2();
    // TODO: fill in arm code once done

    //corner1();
    //corner2();


    

    //corner1();
}