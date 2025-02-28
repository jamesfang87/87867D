#include "auton.h"
#include "pros/rtos.hpp"

ASSET(blueneg1_txt);

void blue_neg() {
    chassis.setPose(-63, 12, 270);
    chassis.follow(blueneg1_txt, 12, 2500, false, false);
    clamp.toggle();
    pros::delay(100);

    intake.move_velocity(10000);
    chassis.turnToPoint(-7, 40, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-7, 40, 1000, {.maxSpeed = 70}, false);

    chassis.turnToPoint(-3.5, 50, 800, {.maxSpeed = 90}, false);
    chassis.moveToPoint(-3.5, 50, 1000, {.maxSpeed = 70}, false);

    chassis.moveToPoint(-11, 39, 1000, {.maxSpeed = 70}, false);

    chassis.moveToPoint(24, 48, 1200, {.maxSpeed = 70}, false);
    intake_lift.toggle();

    chassis.moveToPoint(-65, 65, 3000, {.maxSpeed = 70}, false);

    chassis.moveToPoint(-48, 0, 3000, {.maxSpeed = 70}, false);
}

void red_neg() {
}

void red_elim() {
    

}

void blue_elim() {

}