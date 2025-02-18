#include "skills.h"

ASSET(one_txt);
ASSET(two_txt);
ASSET(three_txt);

Intake in = Intake(); // don't worry abt it
// use with in.run_intake() for intake

// TODO: retest
void high_stake1() {
    // place to robot where back of the robot is right against
    // the black plastic holder for the alliance stake.
    // this distance (from the wall to the metal bar at the back of the robot) is 1.5 inches
    // the preload should be about in the middle
    chassis.setPose(-60.5, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    in.run_intake();
    pros::delay(500);
    in.stop();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    // inconsistent, flucuates most with battery %
    chassis.moveToPoint(-44, 0, 500);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-49, 24, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 10}, false);
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);

    // get ring at (-24, 24) and (24, 48)
    
    //pros::delay(1000);
    in.run_intake();
    chassis.turnToHeading(90, 500, {}, false);
    // also fluctates with battery %
    // tune maximum speed
    // also raise speed at the end so that it can actually intake the last ring
    chassis.follow(one_txt, 14, 6000, true, false);
    pros::delay(100);

    chassis.moveToPoint(0, 47, 2000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(0, 1500);

    //clamp.toggle();  // remove after testing
}

/**
 * Ran after scoring on the left wall stake (viewed from starting side)
 */
void corner1() {
    clamp.toggle();
    pros::delay(200); // remove after testing

    chassis.setPose(0, 47, 0); // remove after testing, maybe not who knows

    // turn to face rings
    chassis.turnToHeading(270, 1000);
    in.run_intake();
    chassis.moveToPoint(-64, 48, 2000, {.maxSpeed = 60, .minSpeed = 10}, false);
    pros::delay(200);
    chassis.moveToPoint(-56, 48, 500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.follow(two_txt, 10, 2500, true, false);

    // put goal into corner

    chassis.moveToPoint(-64.32, 65.6, 1000, {.forwards = false}, false);
    clamp.toggle();
    chassis.moveToPoint(-47, 47, 1000, {}, false);
    chassis.turnToHeading(180, 1000, {}, false);

    // does not move to bottom corner
}

void corner2() {
    // clamp is open at this point
    chassis.moveToPoint(-47, -25, 4000, {.forwards = false, .maxSpeed = 100}, false);
    clamp.toggle();
    pros::delay(100);

    chassis.turnToHeading(29, 1000);
    in.run_intake();
    chassis.follow(three_txt, 12, 4000, true, false);

    chassis.moveToPoint(-56, -63, 2000, {.forwards = false}, false);
    clamp.toggle();
}

void third_goal() {
    chassis.moveToPoint(60, 21, 3000, {.forwards = false}, false);
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);


    chassis.moveToPoint(58.84, -44.5, 2000, {.maxSpeed = 60}, false);

}


void skills() {
    high_stake1();

    // TODO: fill in arm code once done

    corner1();
    //corner2();


    

    //corner1();
}