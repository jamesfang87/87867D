#include "arm.h"

void move_arm_to(float target, float time_limit = 2000) {
    pros::Task task([=]() {
        lemlib::PID arm_pid(1, 0, 1, 50, true);
        float time = 0;

        float pos = arm_encoder.get_angle();
        float error = target - pos;

        printf("arm pos: %f\n", pos);
        printf("target: %f", target);
        printf("%f\n", error);
        while (fabs(error) > 5 && time < time_limit) {
            printf("%f\n", error);
            printf("run\n");
            float output = arm_pid.update(error);
            arm.move_voltage(50 * output);
            error = target - arm.get_position();
            time += 10;
            pros::delay(10);
        }
    });
}

void move_arm_up() {
    arm.move_voltage(12000);
}

void move_arm_down() {
    arm.move_voltage(-12000);
}

void stop_arm() {
    arm.brake();
}