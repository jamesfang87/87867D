#include "skills.h"
#include "lemlib/pose.hpp"
#include "pros/rtos.hpp"

asset(one_txt);

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
    intake.move_velocity(-10);
    chassis.turnToPoint(x, y, 250, {.maxSpeed = 75}, false);
    intake.brake();
    move_arm_to(140, 2000);
    chassis.moveToPoint(x, y, 250, {.maxSpeed = 75}, false);
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
    chassis.moveToPoint(-49, 0, 700);
    chassis.turnToPoint(-49, -25, 600, {.forwards = false}, false);
    chassis.moveToPoint(-49, -25, 800, {.forwards = false, .maxSpeed = 70, .minSpeed = 5}, false);
    toggle_clamp();

    // intake the first ring
    intake.move_velocity(450);
    chassis.moveToPoint(-23.5, -23.5, 800, {.maxSpeed = 90, .minSpeed = 90}, false);
    
    // load this ring onto the arm
    intake.move_velocity(250);
    chassis.moveToPose(27, -47, 108, 2400, {.maxSpeed = 100, .minSpeed = 70});
    pros::delay(1200);
    move_arm_to(22, 800);

    // score ring 1 on high stake
    chassis.moveToPoint(0.5, -42, 1500, {.forwards = false, .maxSpeed = 80}, false);
    intake.brake();
    chassis.turnToPoint(0, -64, 600, {.maxSpeed = 75}, false);
    chassis.moveToPoint(0, -64, 900, {.maxSpeed = 75}, false);
    score_high_stake({0, -64, 0});
    chassis.moveToPoint(0, -48, 900, {.forwards = false, .maxSpeed = 70}, false);
    move_arm_to(0, 4000);

    // intake the 3 collinear rings
    intake.move_velocity(450);
    chassis.turnToPoint(-48, -48, 800, {.maxSpeed = 100}, false);
    chassis.moveToPoint(-48, -48, 1000, {.maxSpeed = 70, .minSpeed = 60}, false);
    intake.move_velocity(490);
    chassis.moveToPoint(-59, -48, 1750, {.maxSpeed = 60, .minSpeed = 20}, false);

    intake.move_velocity(350);
    chassis.moveToPoint(-46, -60, 1200, {.maxSpeed = 65}, false);

    // put goal into corner
    chassis.turnToPoint(-66, -66, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-66, -66, 1000, {.forwards = false, .maxSpeed = 70}, false);
    intake.brake();
    toggle_clamp();
    
    chassis.moveToPoint(47, -47, 3000, {.maxSpeed = 90});
    pros::delay(2000);
    intake.move_velocity(250);
    move_arm_to(22, 800);

    chassis.moveToPose(63, -20, 233, 2000, {.forwards = false, .minSpeed = 40}, false);
    intake.brake();
    toggle_clamp();

// 57, -52

    sweeper.toggle();
    chassis.turnToPoint(60, -55, 600, {}, false);
    chassis.moveToPoint(60, -55, 3000, {}, false);

    chassis.turnToHeading(240, 600);
    chassis.turnToHeading(335, 1000);
    clamp.toggle();

    

    // chassis.turnToPoint(67, -61, 800, {.forwards = false}, false);
    // chassis.moveToPoint(67, -61, 800, {.forwards = false, .minSpeed = 30}, false);
    // clamp.toggle();
    // sweeper.toggle();

    // chassis.moveToPoint(47, 23.5, 1200, {.maxSpeed = 60}, false);
    // chassis.moveToPoint(47, 0, 1500, {.forwards = false, .maxSpeed = 50}, false);
    // toggle_clamp();



    






    

}

