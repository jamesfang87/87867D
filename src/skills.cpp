#include "skills.h"

ASSET(one_txt);

void skills() {
    Intake in = Intake();
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
    chassis.moveToPoint(-46, 0, 500, {.minSpeed = 5});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-50, 24, 1000, {.forwards = false, .maxSpeed = 60}, false);
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
    chassis.follow(one_txt, 10, 4000, true, false);
}