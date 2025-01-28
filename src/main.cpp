#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

#include "robot.h"

#include "driver.h"


/*
clamp = Port B
intake_lift = Port A
*/


// initialize function. Runs on program startup
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading]
            // delay to save resources
            pros::delay(20);
        }
    });
}


void opcontrol() {
    float front_back = 0, left_right = 0;

    // loop forever
    while (true) {
        check_buttons();
        check_intake();
        check_arm();

        // Get joystick positions
        int axis3 = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int axis4 = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int axis1 = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int axis2 = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // Calculate front-back movement
        float front_back = (axis3 > 0) ? sqrt(pow(axis3, 2) + pow(axis4, 2)) :
                           -sqrt(pow(axis3, 2) + pow(axis4, 2));

        // Calculate left-right movement
        float left_right = (axis1 > 0) ? sqrt(pow(axis1, 2) + pow(axis2, 2)) :
                            -sqrt(pow(axis1, 2) + pow(axis2, 2));

        // Apply corrections based on deadzone
        float corrected_front_back = (fabs(front_back) < 9 && front_back != 0) ? 9 * front_back : front_back;
        float corrected_left_right = (fabs(left_right) < 9 && left_right != 0) ? 10 * left_right : left_right;

        // Set motor voltages
        left_motors.move_voltage((((fabs(corrected_front_back) < 9 && corrected_front_back != 0) ? 9 * corrected_front_back : corrected_front_back) -
                                      ((fabs(corrected_left_right) < 9 && corrected_left_right != 0) ? 10 * corrected_left_right : corrected_left_right)) * 127);

        right_motors.move_voltage((((fabs(corrected_front_back) < 9 && corrected_front_back != 0) ? 9 * corrected_front_back : corrected_front_back) +
                                       ((fabs(corrected_left_right) < 9 && corrected_left_right != 0) ? 10 * corrected_left_right : corrected_left_right)) * 127);

        pros::delay(10); // Wait for 10 milliseconds
    }
}

void autonomous() {
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    // chassis.turnToHeading(90, 100000);
	// chassis.moveToPoint(0, 48, 10000);
	chassis.moveToPose(20, 20, 45, 3000, {.minSpeed=127, .earlyExitRange=2});
	chassis.moveToPose(20, 40, 0, 3000, {.minSpeed=100, .earlyExitRange=2});
}