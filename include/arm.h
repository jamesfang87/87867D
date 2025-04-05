#include "robot.h"

#ifndef ARM_H
#define ARM_H

void move_arm_to(float target, int time_limit);
void move_arm_to_fast(float target, int time_limit);
void move_arm_up();
void move_arm_down();
void stop_arm();

#endif