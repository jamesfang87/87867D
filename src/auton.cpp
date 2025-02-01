#include "auton.h"

void blue_neg() {
    //clamp.toggle();
    chassis.setPose(42, 60, 0);
    //chassis.turnToHeading(150, 4000);
    chassis.moveToPose(60, 20, -35, 4000, {.forwards = false, .maxSpeed = 127, .minSpeed = 70}, false);
    
    clamp.toggle();
    pros::delay(200);
    
    //chassis.turnToPoint(48, 24, 1000, {}, false);
    //chassis.moveToPoint(36, 24, 1000, {}, false);
    //chassis.turnToHeading(-90, 4000, {}, false);
}