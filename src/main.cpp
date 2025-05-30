// STD library imports 
#include <cstdio>

// Lemlib/Pros includes
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

// User defined file imports
#include "pros/rtos.hpp"
#include "robot.h"
#include "driver.h"
#include "auton.h"
#include "skills.h"


// initialize function. Runs on program startup
void initialize() {
    pros::lcd::initialize(); // initialize brain screen

    chassis.calibrate(); // calibrate sensors
    arm.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    arm_encoder.set_position(0);

    vertical_encoder.set_data_rate(5);
    horizontal_encoder.set_data_rate(5);
    imu.set_data_rate(5);

    // print position to brain screen
    pros::Task screen_task([&]() {
        double first = imu.get_heading();
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            pros::lcd::print(3, "horizontal: %f", horizontal_tracking_wheel.getDistanceTraveled());
            pros::lcd::print(4, "vertical: %f", vertical_tracking_wheel.getDistanceTraveled());
            // delay to save resources
            pros::delay(10);
        }
    });
}

void opcontrol() {
    arm.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    
    // loop forever
    while (true) {
        check_buttons();
        check_intake();
        check_arm();

        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX * 0.5);

        pros::delay(10); // Wait for 10 milliseconds
    }
}

void autonomous() {
    // skills();
    // red_pos(); 
    // red_neg();
    // blue_neg();
    // blue_pos();
    // red_elim();
    // blue_elim();
}