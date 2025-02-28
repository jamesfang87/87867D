#include "skills.h"
#include <cstdio>
#include "pros/rtos.hpp"

ASSET(one_txt);
ASSET(two_txt);
ASSET(three_txt);
ASSET(four_txt);
ASSET(five_txt);
ASSET(six_txt);

/**
 * @brief The start of the skills run. This scores the entire first corner.
 * Place to robot where back of the robot is right against
 * the black plastic holder for the alliance stake.
 * This distance (from the wall to the metal bar at the back of the robot) is 1.5 inches.
 * The preload should be about in the middle
 */
void corner1() {
    chassis.setPose(-63, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    intake.move_voltage(10000);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    // inconsistent, fluctuates most with battery %
    chassis.moveToPoint(-48, 0, 700);
    chassis.turnToHeading(180, 700);
    chassis.moveToPoint(-48, 24, 1000, {.forwards = false, .maxSpeed = 70, .minSpeed = 10}, false);
    
    // clamp goal
    pros::delay(100);
    clamp.toggle();
    pros::delay(100);

    // get ring at (-24, 24) and (24, 48)
    intake.move_voltage(10000);
    chassis.turnToHeading(90, 700, {}, false);
    chassis.follow(one_txt, 11, 4000, true, false);
    pros::delay(75);

    chassis.moveToPoint(0, 49.6, 1500, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(-90, 800, {.maxSpeed = 80}, false);

    // intake the 3 collinear rings
    chassis.moveToPoint(-59, 49.6, 2750, {.maxSpeed = 48, .minSpeed = 10}, false);
    pros::delay(600);  // wait to intake ring
    

    chassis.moveToPoint(-44, 61, 1200, {.maxSpeed = 60}, false);
    pros::delay(200);  // wait to intake ring

    // put goal into corner
    chassis.turnToPoint(-58, 65, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-58, 65, 1100, {.forwards = false, .maxSpeed = 70}, false);
    
    pros::delay(100);
    clamp.toggle();
    intake.brake();
    pros::delay(100);

    // moves to y = 0
    // TODO: test this part so we can link up with corner2()
    chassis.moveToPoint(-47, 47, 1000 ,{.maxSpeed = 90}, false);
    chassis.turnToHeading(0, 1500, {.maxSpeed = 90, .minSpeed = 20}, false);
    printf("what : %f", chassis.getPose().x);

    chassis.moveToPoint(-47, 0, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 5,}, false);
    

}
/**
 * @brief Scores the second corner.
 */
void corner2() {
    // get mobile goal; note: clamp is open at this point
    chassis.moveToPoint(-47, -25, 1500, {.forwards = false, .maxSpeed = 60}, false);
    clamp.toggle();
    pros::delay(100);

    // intake 2 rings, moving into position to intake the rest
    intake.move_voltage(10000);
    chassis.follow(two_txt, 12, 3500, true, false);

    chassis.moveToPoint(0, -47, 1000, {.forwards = false, .maxSpeed = 70}, false);
    chassis.turnToHeading(266.5, 800, {.maxSpeed = 80}, false);

    chassis.setPose(chassis.getPose().x, -48, -90); // !do not remove
    imu.set_heading(270);

    // // intake the 3 collinear rings
    //intake.move_voltage(12000);
    chassis.moveToPoint(-59, -48, 2000, {.maxSpeed = 60, .minSpeed = 10}, false);
    pros::delay(600);  // wait to intake ring
    
    chassis.moveToPoint(-42, -62, 2000, {.maxSpeed = 65}, false);
    pros::delay(400);  // wait to intake ring

    // put goal into corner
    chassis.turnToPoint(-57, -65, 800, {.forwards = false, .maxSpeed = 80}, false);
    chassis.moveToPoint(-57, -65, 1200, {.forwards = false, .maxSpeed = 60}, false);
    clamp.toggle();
    intake.brake();

    pros::delay(200);

    chassis.turnToPoint(60, -24, 700, {.forwards = true, .maxSpeed = 80}, false);
    chassis.moveToPoint(34, -33, 2000, {.forwards = true, .maxSpeed = 90}, false);
    chassis.moveToPoint(63, -21, 2000, {.forwards = false, .maxSpeed = 60}, false);
    clamp.toggle();
    pros::delay(200);

    chassis.moveToPoint(66, -59, 1500, {.forwards = false, .maxSpeed = 80}, false);
    clamp.toggle();

    chassis.moveToPoint(48, -24, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(48, 0, 1700, {.forwards = false, .maxSpeed = 50}, false);
    clamp.toggle();
    pros::delay(200);

    intake.move_voltage(10000);
    chassis.moveToPoint(24, -24, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(0, 0, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(24, 24, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(24, 48, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(48, 48, 1500, {.maxSpeed = 70}, false);
    chassis.moveToPoint(48, 60, 1500, {.maxSpeed = 70} ,false);
    chassis.moveToPoint(67, 65, 1500, {.forwards = false, .maxSpeed = 90}, false);
    clamp.toggle();
    // imu.set_heading(imu.get_heading() + 1.8);
    // chassis.setPose(chassis.getPose().x, chassis.getPose().y, imu.get_heading());
}

void skills() {
    corner1();
    corner2();
}