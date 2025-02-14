#include "auton.h"

ASSET(move1_txt);
ASSET(move2_txt);

ASSET(first_goal_txt);
ASSET(first_ring_txt);
ASSET(move_back_txt);
ASSET(second_ring_txt);
ASSET(move_back2_txt);
ASSET(last_ring_txt);

ASSET(elimgoal1_txt);
ASSET(last_txt);

void blue_neg() {
    chassis.setPose(59.814, 36.858, 90);
    // lookahead distance: 15 inches

    // follow path, backward - drive to stake1
    chassis.follow(move1_txt, 15, 3000, false, false);
    clamp.toggle();
    pros::delay(175);
    intake.move_velocity(12000);

    chassis.follow(move2_txt, 15, 9000, true, false);
}

void red_neg() {
    chassis.setPose(-58.43, 34.483, 270);

    // path, lookahead, time limit, forward, async

    // get the first goal
    chassis.follow(first_goal_txt, 15, 2000, false, false);
    clamp.toggle();
    pros::delay(400);
    intake.move_velocity(12000);

    // now get the first ring (right above the first goal);
    chassis.follow(first_ring_txt, 15, 2000, true, false);
    pros::delay(400);

    // move back a bit
    //chassis.follow(move_back_txt, 15, 2000, false, false);

    // go for the second ring (closer ring to the middle)
    //chassis.follow(second_ring_txt, 15, 2000, true, false);

    // move back a bit again
    //chassis.follow(move_back2_txt, 15, 2000, false, false);

    // get the last ring
    //chassis.follow(last_ring_txt, 14, 2000, true, false);
}

void red_elim() {
    
    //arm.move_absolute(450, 400);
    //arm.move_absolute(0, 400);


    chassis.setPose(-61.883, -15.74, 270);
    chassis.follow(elimgoal1_txt, 15, 2000, false, false);
    clamp.toggle();
    pros::delay(400);
    intake.move_velocity(12000);
    pros::delay(500);

    chassis.turnToPoint(-23.305, -46.602, 1000, {}, false);
    pros::delay(100);

    chassis.follow(last_txt, 15, 2000, true, false);

}

ASSET(blueelimposgoal1_txt)
ASSET(bluelast_txt)

void blue_elim() {
    chassis.setPose(61.883, -15.74, 270);
    chassis.follow(blueelimposgoal1_txt, 15, 2000, false, false);
    clamp.toggle();
    pros::delay(400);
    intake.move_velocity(12000);
    pros::delay(500);

    chassis.turnToPoint(23.305, -46.602, 1000, {}, false);
    pros::delay(100);

    chassis.follow(bluelast_txt, 15, 2000, true, false);

}