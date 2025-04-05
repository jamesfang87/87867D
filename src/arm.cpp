#include "arm.h"

/**
 * @brief Moves the arm to a specified position (target)
 * 
 * @param target The position to move the arm to
 * @param time_limit The maximum time the motion can take before exiting
 */
void move_arm_to(float target, int time_limit = 2000) {
    pros::Task task([=]() {
        lemlib::PID arm_pid(3.5, 0, 8, 12, true);
        int time = 0;

        float error = target - arm_encoder.get_position() / 100.0;
        while (fabs(error) > 0.1 && time < time_limit) {
            float output = arm_pid.update(error);
            arm.move_velocity(output);
            error = target - arm_encoder.get_position() / 100.0;
            time += 10;
            pros::delay(10);
        }
        stop_arm();
    });
}

/**
 * @brief Moves the arm up (away from the inital position)
 */
void move_arm_up() {
    arm.move_velocity(600);
}

/**
 * @brief Moves the arm down (towards the inital position)
 */
void move_arm_down() {
    arm.move_velocity(-600);
}

/**
 * @brief Stops the arm from moving
 */
void stop_arm() {
    arm.brake();
}