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
    chassis.setPose(-60.5, 0, 90);
    arm.set_zero_position_all(0);

    // score alliance stake
    intake.move_voltage(12000);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    // inconsistent, fluctuates most with battery %
    chassis.moveToPoint(-47, 0, 500);
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-47, 24, 1000, {.forwards = false, .maxSpeed = 60, .minSpeed = 10}, false);
    
    // clamp goal
    pros::delay(100);
    clamp.toggle();
    pros::delay(100);

    // get ring at (-24, 24) and (24, 48)
    intake.move_voltage(12000);
    chassis.turnToHeading(90, 500, {}, false);
    chassis.follow(one_txt, 11, 3500, true, false);
    pros::delay(75);

    chassis.moveToPoint(0, 49.6, 1200, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(-90, 750, {.maxSpeed = 80}, false);

    // intake the 3 collinear rings
    intake.move_voltage(12000);
    chassis.moveToPoint(-59, 49, 2750, {.maxSpeed = 48, .minSpeed = 10}, false);
    pros::delay(600);  // wait to intake ring
    

    chassis.moveToPoint(-44, 61, 2000, {.maxSpeed = 60}, false);
    pros::delay(400);  // wait to intake ring

    // put goal into corner
    chassis.moveToPoint(-61, 61, 2500, {.forwards = false, .maxSpeed = 70}, false);
    imu.set_heading(141.7);
    chassis.setPose(chassis.getPose().x, chassis.getPose().y, imu.get_heading());
    
    printf("%f\n", chassis.getPose().x);
    printf("%f\n", chassis.getPose().y); 
    printf("%f\n", chassis.getPose().theta); 
    pros::delay(100);
    clamp.toggle();
    intake.brake();
    pros::delay(100);

    // moves to y = 0
    // TODO: test this part so we can link up with corner2()
    chassis.moveToPoint(-44, 47, 1200 ,{.maxSpeed = 70}, false);
    chassis.turnToHeading(0, 1200, {.maxSpeed = 80}, false);
    chassis.setPose(-47, chassis.getPose().y, chassis.getPose().theta);
    printf("%f\n", chassis.getPose().x);
    printf("%f\n", chassis.getPose().y); 
    printf("%f\n", chassis.getPose().theta);
}

/**
 * @brief Scores the second corner.
 */
void corner2() {
    // get mobile goal; note: clamp is open at this point
    chassis.moveToPoint(-44, -25, 3000, {.forwards = false, .maxSpeed = 60}, false);
    clamp.toggle();
    pros::delay(100);

    // intake 2 rings, moving into position to intake the rest
    intake.move_voltage(12000);
    chassis.follow(two_txt, 12, 3000, true, false);

    chassis.moveToPoint(0, -46, 2000, {.forwards = false, .maxSpeed = 60}, false);
    chassis.turnToHeading(266.5, 750, {.maxSpeed = 80}, false);

    chassis.setPose(0, -48, -90); // !do not remove
    imu.set_heading(270);

    // // intake the 3 collinear rings
    intake.move_voltage(12000);
    chassis.moveToPoint(-59, -48, 2000, {.maxSpeed = 50, .minSpeed = 10}, false);
    pros::delay(600);  // wait to intake ring
    
    chassis.moveToPoint(-42, -62, 2000, {.maxSpeed = 60}, false);
    pros::delay(400);  // wait to intake ring

    // put goal into corner
    chassis.moveToPoint(-61, -61, 2000, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    intake.brake();

    pros::delay(100);
    // imu.set_heading(imu.get_heading() + 1.8);
    // chassis.setPose(chassis.getPose().x, chassis.getPose().y, imu.get_heading());
}

/**
 * @brief Moves to and scores the opposite alliance stake
 */
void opposite_alliance_stake() {
    intake.move_voltage(12000);
    chassis.follow(three_txt, 12, 4000, true);
    pros::delay(3500);
    intake.brake();



    // TODO: set position by aligning with wall
}

/**
 * @brief Fills up and scores the 3rd goal
 */
void third_goal() {
    // the goal is already clamped
    chassis.setPose(62, 0, 90);
    chassis.moveToPoint(44, 0, 1500, { .forwards = false, .maxSpeed = 60}, false);
    clamp.toggle();
    chassis.turnToHeading(227, 1000, {.maxSpeed = 80}, false);

    intake.move_velocity(12000);
    chassis.follow(four_txt, 14, 10000, true, false);
    chassis.moveToPoint(59, 47, 1000, {.maxSpeed = 60});

    // put goal in corner
    chassis.moveToPoint(-61, -61, 2000, {.forwards = false, .maxSpeed = 70}, false);
    clamp.toggle();
    intake.brake();

    // end run
}


void skills() {
    corner1();
    corner2();
    //opposite_alliance_stake();
    //third_goal();
}