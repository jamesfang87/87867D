#include "arm.h"

/**
 * @brief Moves the arm to a specified position (target)
 * 
 * @param target The position to move the arm to
 * @param time_limit The maximum time the motion can take before exiting
 */
void move_arm_to(float target, float time_limit = 2000) {
    pros::Task task([=]() {
        lemlib::PID arm_pid(0.7, 0, 3, 50, true);
        float time = 0;

        float pos = arm_encoder.get_angle();
        float error = target - pos;
        while (fabs(error) > 5 && time < time_limit) {
            float output = arm_pid.update(error);
            arm.move_velocity(output);
            error = target - arm.get_position();
            time += 10;
            pros::delay(10);
        }
    });
}

/**
 * @brief Moves the arm up (away from the inital position)
 */
void move_arm_up() {
    arm.move_velocity(500);
}

/**
 * @brief Moves the arm down (towards the inital position)
 */
void move_arm_down() {
    arm.move_velocity(-500);
}

/**
 * @brief Stops the arm from moving
 */
void stop_arm() {
    arm.brake();
}