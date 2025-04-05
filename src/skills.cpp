#include "skills.h"
#include "lemlib/pose.hpp"
#include "pros/rtos.hpp"

/**
 * @brief Util function to toggle the state of the clamp; use to both clamp and release goals 
 */
void toggle_clamp() {
    pros::delay(100);
    clamp.toggle();
    pros::delay(100);
}

/**
 * @brief Util function to score a single ring onto the high stake. 
 * @pre the arm is already holding a ring and the robot is already in position to score
 * 
 * @param stake_pos the coordinates of the high stake which the robot should score on 
 */
void score_high_stake(lemlib::Pose stake_pos) {
    auto [x, y, _] = stake_pos;
    intake.move_velocity(-90);
    chassis.turnToPoint(x, y, 500, {.maxSpeed = 75}, false);
    intake.move_velocity(0);
    move_arm_to(135, 2000);
    chassis.moveToPoint(x, y, 800, {.maxSpeed = 75}, false);
}

void skills() {
    chassis.setPose(-63, 0, 90);
    arm_encoder.set_position(0);
    arm.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);

    // score alliance stake
    intake.move_velocity(350);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    chassis.moveToPoint(-48, 0, 800);
    chassis.turnToPoint(-48, 24, 700, {.forwards = false}, false);
    chassis.moveToPoint(-48, 24, 1000, {.forwards = false, .maxSpeed = 70, .minSpeed = 5}, false);
    toggle_clamp();

    // intake the first ring
    intake.move_velocity(355);
    chassis.moveToPoint(-23.5, 23.5, 800, {.maxSpeed = 70}, false);
    
    // WTF MY ROBOT IS TOO FAT
    intake.move_velocity(400);
    chassis.moveToPose(23.5, 47, 72, 2000, {.maxSpeed = 90, .minSpeed = 55}, false);
    
    // load this ring onto the arm
    intake.move_velocity(370);
    chassis.turnToPoint(47, 59, 600, {.maxSpeed = 127, .minSpeed = 40});  // ! check the min speed
    chassis.moveToPoint(47, 59, 1200, {.maxSpeed = 70, .minSpeed = 20});
    move_arm_to(25, 800);

    // score ring 1 on high stake
    chassis.moveToPoint(0.5, 40, 1500, {.forwards = false, .maxSpeed = 80}, false);
    chassis.turnToPoint(0, 64, 600, {.maxSpeed = 75}, false);
    chassis.moveToPoint(0, 64, 900, {.maxSpeed = 75}, false);
    score_high_stake({0, 64, 0});
    chassis.moveToPoint(0, 52, 600, {.forwards = false, .maxSpeed = 70}, false);

    // ring 2
    move_arm_to(20, 1000);
    pros::delay(1000);
    intake.move_velocity(365);
    chassis.moveToPoint(0, 64, 1000, {.maxSpeed = 75}, false);
    score_high_stake({0, 64});
    chassis.moveToPoint(0, 48, 1000, {.forwards = false, .maxSpeed = 70}, false);
    move_arm_to(0, 2000);

    // intake the 3 collinear rings
    intake.move_velocity(370);
    chassis.turnToPoint(-48, 48, 800, {.maxSpeed = 100}, false);
    chassis.turnToPoint(-48, 48, 1000, {.maxSpeed = 80, .minSpeed = 70}, false);
    intake.move_velocity(475);
    chassis.moveToPoint(-59, 48, 1750, {.maxSpeed = 70, .minSpeed = 10}, false);

    intake.move_velocity(350);
    chassis.moveToPoint(-44, 64, 1200, {.maxSpeed = 65}, false);
    pros::delay(200);  // wait to intake ring

    // put goal into corner
    chassis.turnToPoint(-58, 65, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-58, 65, 1100, {.forwards = false, .maxSpeed = 70}, false);
    intake.brake();
    toggle_clamp();

    // move to the other side of the field and clamp the goal
    chassis.moveToPoint(-48, 48, 1000 ,{.maxSpeed = 90}, false);
    chassis.turnToHeading(0, 1500, {.maxSpeed = 90, .minSpeed = 20}, false);
    chassis.moveToPoint(-48, 0, 1500, {.forwards = false, .minSpeed = 60, .earlyExitRange = 5,}, false);
    chassis.moveToPoint(-48, -25, 1500, {.forwards = false, .maxSpeed = 55}, false);
    toggle_clamp();
    
    // // intake 2 rings, moving into position to intake the rest
    // intake.move_velocity(350);
    // chassis.follow(two_txt, 12, 3500, true, false);

    // chassis.moveToPoint(0, -47, 1000, {.forwards = false, .maxSpeed = 70}, false);
    // chassis.turnToHeading(270, 800, {.maxSpeed = 80}, false);

    // // intake the 3 collinear rings
    // intake.move_velocity(350);
    // chassis.moveToPoint(-48, -48, 1250, {.maxSpeed = 45, .minSpeed = 27}, false);
    // intake.move_velocity(400);
    // chassis.moveToPoint(-59, -48, 1000, {.maxSpeed = 42.5, .minSpeed = 10}, false);
    // pros::delay(400);  // wait to intake ring
    // intake.move_velocity(340);

    // chassis.moveToPoint(-44, -64, 2000, {.maxSpeed = 65}, false);
    // pros::delay(400);  // wait to intake ring

    // // put goal into corner
    // chassis.turnToPoint(-57, -65, 800, {.forwards = false, .maxSpeed = 80}, false);
    // chassis.moveToPoint(-57, -65, 1200, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // intake.brake();
    // pros::delay(200);
    
    // chassis.turnToPoint(60, -24, 700, {.forwards = true, .maxSpeed = 80}, false);
    // chassis.moveToPoint(34, -33, 2000, {.forwards = true, .maxSpeed = 90}, false);
    // chassis.moveToPoint(60, -24, 2000, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // pros::delay(200);

    // // put goal in corner
    // chassis.moveToPoint(66, -59, 1700, {.forwards = false, .maxSpeed = 80}, false);
    // clamp.toggle();
    // pros::delay(200);

    // // get into a more favorable position to clamp onto the middle mobile goal
    // chassis.moveToPoint(48, -24, 1500, {.maxSpeed = 70}, false);
    // // get the middle mogo and clamp
    // chassis.moveToPoint(48, 0, 1700, {.forwards = false, .maxSpeed = 60}, false);
    // clamp.toggle();
    // pros::delay(200);


    // // get the 6 rings left on the opposite side
    // intake.move_velocity(400);
    // chassis.moveToPoint(24, -24, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(0, 0, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(24, 24, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(24, 48, 1700, {.maxSpeed = 70}, false);
    // chassis.moveToPoint(48, 48.5, 1800, {.maxSpeed = 70}, false);
    // intake.move_velocity(420);
    // chassis.moveToPoint(48, 64, 1700, {.maxSpeed = 70} ,false);
    
    // // put into corner
    // chassis.moveToPoint(59, 78, 2000, {.forwards = false, .maxSpeed = 90}, false);
    // clamp.toggle();
    // pros::delay(1200);

    // // HANGGGGGG!!!!!!!
    // intake.brake();
    // move_arm_to(700, 1500);
    // move_arm_to(0, 1500);
    // chassis.moveToPoint(24, 24, 2000, {.forwards = true, .maxSpeed = 70}, false);
    // move_arm_to(1500, 1500);
    // arm.brake();
    // chassis.moveToPoint(0, 0, 1500, {.forwards = false, .maxSpeed = 65}, false);
    // move_arm_to(0, 1500);
    // arm.brake();
}