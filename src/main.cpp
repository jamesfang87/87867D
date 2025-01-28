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
    // loop forever
    while (true) {
        // first check buttons
        check_buttons();

        // 
        check_intake();

        // 
        check_arm();



        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);

        // delay to save resources
        pros::delay(25);
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