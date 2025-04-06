#include "skills.h"
#include "lemlib/pose.hpp"
#include "pros/llemu.hpp"
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
    intake.move_velocity(-80);
    chassis.turnToPoint(x, y, 500, {.maxSpeed = 75}, false);
    intake.brake();
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
    chassis.moveToPoint(-49, 0, 800);
    chassis.turnToPoint(-49, 24, 700, {.forwards = false}, false);
    chassis.moveToPoint(-49, 24, 1000, {.forwards = false, .maxSpeed = 70, .minSpeed = 5}, false);
    toggle_clamp();

    // intake the first ring
    intake.move_velocity(355);
    chassis.moveToPoint(-23.5, 23.5, 800, {.maxSpeed = 70}, false);
    
    // load this ring onto the arm
    intake.move_velocity(330);
    chassis.moveToPose(25, 47, 72, 2000, {.maxSpeed = 90, .minSpeed = 55});
    pros::delay(1200);
    move_arm_to(20, 800);

    // score ring 1 on high stake
    chassis.moveToPoint(0.5, 42, 1500, {.forwards = false, .maxSpeed = 80}, false);
    intake.brake();
    chassis.turnToPoint(0, 64, 600, {.maxSpeed = 75}, false);
    chassis.moveToPoint(0, 64, 900, {.maxSpeed = 75}, false);
    score_high_stake({0, 64, 0});
    chassis.moveToPoint(0, 48, 600, {.forwards = false, .maxSpeed = 70});
    move_arm_to(0, 2000);

    // intake the 3 collinear rings
    intake.move_velocity(400);
    chassis.turnToPoint(-48, 48, 800, {.maxSpeed = 100}, false);
    chassis.moveToPoint(-48, 48, 1000, {.maxSpeed = 70, .minSpeed = 60}, false);
    intake.move_velocity(480);
    chassis.moveToPoint(-59, 48, 1750, {.maxSpeed = 60, .minSpeed = 10}, false);

    intake.move_velocity(350);
    chassis.moveToPoint(-44, 64, 1200, {.maxSpeed = 65}, false);
    pros::delay(200);  // wait to intake ring

    // put goal into corner
    chassis.turnToPoint(-65, 65, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-65, 65, 1000, {.forwards = false, .maxSpeed = 70}, false);
    intake.brake();
    toggle_clamp();


    // TODO: Tune
    // move across the field and load ring into arm
    chassis.moveToPoint(24, 50, 1500, {.minSpeed = 90}, false);
    move_arm_to(21, 800);
    intake.move_velocity(300);
    chassis.moveToPoint(48, 48, 1000, {.maxSpeed = 50}, false);
    
    // grab mobile goal
    chassis.moveToPoint(60, 24, 1500, {.forwards = false, .maxSpeed = 55}, false);
    intake.brake();
    toggle_clamp();
    
    // put goal into corner
    chassis.turnToPoint(66, 60, 600, {.forwards = false, .maxSpeed = 90}, false);
    chassis.moveToPoint(66, 60, 1000, {.forwards = false, .maxSpeed = 70}, false);
    toggle_clamp();

    // move to middle goal
    chassis.moveToPoint(60, 24, 1500, {.maxSpeed = 70}, false);
    chassis.turnToPoint(48, 0, 800, {.maxSpeed = 90}, false);

    pros::lcd::print(5, "left: %i | right: %i", left_motors.get_temperature(), right_motors.get_temperature());
    pros::lcd::print(5, "arm: %i | intake: %i", arm.get_temperature(), intake.get_temperature());
}