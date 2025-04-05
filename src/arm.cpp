#include "arm.h"
#include <cmath>

/**
 * @brief Moves the arm to a specified position (target)
 * 
 * @param target The position (in degrees) to move the arm to
 * @param time_limit The maximum time the motion can take before exiting
 */
void move_arm_to(float target, int time_limit) {
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
 * @brief Moves the arm to a specified position quickly. It does not care about accuracy
 * and its goal is to reach the target position as fast as possible.
 * !this might oscillate like crazy; need testing
 * @warning this might oscillate like crazy 
 * @param target the position (in degrees) to move the arm to
 * @param time_limit The maximum time the motion can take before exiting
 */
void move_arm_to_fast(float target, int time_limit) {
    int time = 0;
    float error = target - arm_encoder.get_position() / 100.0;
    float prev_error = error;  // for now
    while (fabs(error) < 0.1 && time < time_limit) {
        arm.move_velocity(500);

        prev_error = error;
        error = target - arm_encoder.get_position() / 100.0;
        if (std::signbit(prev_error) != std::signbit(error)) {
            break;  // break if we have exceeded the target
        }        
        time += 10;
        pros::delay(10);
    }
    stop_arm();
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