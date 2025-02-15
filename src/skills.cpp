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
    //intake.move_voltage(0);

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    chassis.moveToPoint(-46, 0, 500, {.minSpeed = 5});
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-50, 24, 1000, {.forwards = false, .maxSpeed = 60}, false);
    pros::delay(100);
    clamp.toggle();
    pros::delay(50);

    // get ring at (-24, 24)
    
    //pros::delay(1000);
    in.run_intake();
    chassis.turnToHeading(90, 500, {}, false);
    
    //intake.move_velocity(12000);
    //chassis.moveToPoint(-16, 24, 1000, {.minSpeed = 10}, false);
    
    //pros::delay(1000);

    // get ring at (24, 47)
    chassis.follow(one_txt, 10, 4000, true, false);
}