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
    intake.move_velocity(-30);
    chassis.turnToPoint(x, y, 400, {.maxSpeed = 75}, false);
    intake.brake();
    move_arm_to(140, 2000);
    chassis.moveToPoint(x, y, 300, {.maxSpeed = 75}, false);
}

void skills() {
    // TODO: add early exit range param to motions
    // init settings
    chassis.setPose(-63, 0, 90);
    arm_encoder.set_position(0);
    arm.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);

    // score alliance stake
    intake.move_velocity(350);
    pros::delay(500);
    intake.brake();

    // move forward and turn towards goal on left side of the robot (viewed from red side)
    chassis.moveToPoint(-49, 0, 700);
    chassis.turnToPoint(-49, -26, 600, {.forwards = false}, false);
    chassis.moveToPoint(-49, -26, 800, {.forwards = false, .maxSpeed = 90, .minSpeed = 5}, false);
    toggle_clamp();

    // intake the first ring
    chassis.turnToPoint(-23.5, -25, 600, {}, false);
    intake.move_velocity(400);
    chassis.moveToPoint(-23.5, -25, 600, {.maxSpeed = 90, .minSpeed = 70}, false);
    
    // load this ring onto the arm
    chassis.turnToPoint(23.5, -47, 400, {.maxSpeed= 90, .minSpeed = 75}, false);
    chassis.moveToPoint(23.5, -47, 1400, {.maxSpeed = 90, .minSpeed = 55}, true);    
    pros::delay(1200);
    intake.move_velocity(250);
    move_arm_to(22, 800);

    // score ring 1 on high stake
    chassis.moveToPoint(0, -42, 1500, {.forwards = false, .maxSpeed = 80}, false);
    intake.brake();
    chassis.turnToPoint(0, -64, 600, {.maxSpeed = 75}, false);
    chassis.moveToPoint(0, -64, 900, {.maxSpeed = 75}, false);
    score_high_stake({0, -64, 0});
    chassis.moveToPoint(0, -48, 800, {.forwards = false, .maxSpeed = 80}, false);
    move_arm_to(70, 4000);

    // intake the 3 collinear rings
    intake.move_velocity(400);
    chassis.turnToPoint(-48, -48, 800, {.maxSpeed = 100}, false);
    chassis.moveToPoint(-48, -48, 1000, {.maxSpeed = 70, .minSpeed = 65}, false);
    intake.move_velocity(495);
    chassis.moveToPoint(-59, -48, 1750, {.maxSpeed = 65, .minSpeed = 40}, false);

    intake.move_velocity(350);
    chassis.moveToPoint(-45.5, -61, 1200, {.maxSpeed = 70}, false);

    // put goal into corner
    chassis.turnToPoint(-66, -66, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-66, -66, 800, {.forwards = false, .maxSpeed = 70}, false);
    intake.brake();
    toggle_clamp();
    
    // move to other side and load ring at (47, 47) into arm
    chassis.moveToPoint(49, -47, 3000, {.maxSpeed = 105, .minSpeed = 30});
    pros::delay(2000);
    intake.move_velocity(250);
    move_arm_to(22, 800);

    // get goal and put into corner
    chassis.moveToPoint(47, -47, 600, {.forwards = false, .minSpeed = 50}, false);
    chassis.moveToPose(63, -21, 233, 1500, {.forwards = false, .minSpeed = 30}, false);
    intake.brake();
    toggle_clamp();
    chassis.turnToPoint(58, -58, 600, {.forwards = false}, false);
    chassis.moveToPoint(58, -58, 1600, {.forwards = false}, false);
    toggle_clamp();

    // clamp goal at y = 0
    chassis.moveToPoint(47, -23.5, 1500, {.maxSpeed = 70}, false);
    chassis.turnToPoint(47, 0, 800, {.forwards = false});
    chassis.moveToPoint(47, 0, 1300, {.forwards = false, .maxSpeed = 70}, false);
    toggle_clamp();

    // score onto alliance stake
    chassis.turnToPoint(59, 0, 800, {}, false);
    chassis.moveToPoint(59, 0, 2000, {.maxSpeed = 60}, false);
    chassis.moveToPoint(59, 0, 1000);
    move_arm_to(200, 1000);
    chassis.moveToPoint(47, 0, 2000, {.forwards = false, .maxSpeed = 60});
    move_arm_to(0, 1500);




    // TODO: other corner, speed above part up,
    // chassis.turnToPoint(23.5, -23.5, 500);
    // intake.move_velocity(450);
    // chassis.moveToPoint(23.5, -23.5, 1200);
    // chassis.turnToPoint(0, 0, 2000, {.maxSpeed = 60});
    // intake.brake();
    // chassis.moveToPoint(-23.5, 23.5, 4000);
    // intake.move_velocity(450);
    // chassis.moveToPoint(-47, 47, 2000);


}

void part2() {
    // ! Remove when merging
    chassis.setPose(47, 0, 90);
    arm_encoder.set_position(0);
    arm.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    toggle_clamp();
    // ! Remove when merging

    intake.move_velocity(375);  // TODO: test do see if we need to increase rpm
    chassis.turnToPoint(23.5, -23.5, 500, {}, false);
    chassis.moveToPoint(23.5, -23.5, 1200, {.maxSpeed = 100, .earlyExitRange = 0.1}, false);
    chassis.turnToPoint(0, 0, 2000, {.maxSpeed = 60}, false);
    intake.brake();
    chassis.moveToPoint(-23.5, 23.5, 4000, {.maxSpeed = 80, .earlyExitRange = 0.1}, false);
    intake.move_velocity(450);
    chassis.moveToPoint(-47, 47, 2000, {.maxSpeed = 80}, false);
    chassis.turnToPoint(-60, 47, 600, {}, false);
    chassis.moveToPoint(-60, 47, 1000, {.maxSpeed = 60}, false);
    chassis.turnToPoint(-46, 60, 600, {}, false);
    chassis.moveToPoint(-46, 60, 1000, {.maxSpeed = 60}, false);

    // put goal into corner
    chassis.turnToPoint(-66, 66, 600, {.forwards = false, .maxSpeed = 95}, false);
    chassis.moveToPoint(-66, 66, 800, {.forwards = false, .maxSpeed = 70}, false);
    intake.brake();
    toggle_clamp();

    move_arm_to(22, 800);
    chassis.turnToPoint(-23.5, 47, 600, {}, false);
    intake.move_velocity(250);
    chassis.moveToPoint(-23.5, 47, 1200, {.maxSpeed = 80}, false);

    chassis.turnToPoint(-47, 23.5, 600, {.forwards = false}, false);
    chassis.moveToPoint(-47, 23.5, 1500, {.maxSpeed = 80}, false);

    chassis.moveToPoint(0, 42, 1500, {.forwards = false, .maxSpeed = 80}, false);
    intake.brake();
    chassis.turnToPoint(0, 64, 600, {.maxSpeed = 75}, false);
    chassis.moveToPoint(0, 64, 900, {.maxSpeed = 75}, false);
    score_high_stake({0, 64, 0});
    chassis.moveToPoint(0, 48, 800, {.forwards = false, .maxSpeed = 80}, false);
    move_arm_to(70, 4000);

    intake.move_velocity(400);
    chassis.moveToPoint(23.5, 47, 1200, {.maxSpeed = 80}, false);
    chassis.moveToPoint(23.5, 23.5, 1200, {.maxSpeed = 80}, false);
    chassis.moveToPoint(47, 47, 1200, {.maxSpeed = 80}, false);

    chassis.turnToPoint(60, 47, 600, {}, false);
    chassis.moveToPoint(60, 47, 1000, {.maxSpeed = 60}, false);
    chassis.turnToPoint(46, 60, 600, {}, false);
    chassis.moveToPoint(46, 60, 1000, {.maxSpeed = 60}, false);


    // just need to sweep and hang

}