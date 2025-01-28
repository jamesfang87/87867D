#include "driver.h"

/**
 * Prints the temperatures of the left mg, right mg, and the intake motor
 * to the brain screen.
 * 
 * @return none
 */
void output_temps() {
    controller.print(0, 0, "left motors: %f", left_motors.get_temperature());
    controller.print(1, 0, "right motors: %f", right_motors.get_temperature());
    controller.print(2, 0, "intake: %f", intake.get_temperature());
}

/**
 * Performs a single check of the buttons.
 * 
 * A: Toggle the state of the clamp
 * B: Output the temperatures of the left mg, right mg, and intake (see output_temps())
 * Y: Toggle the state of the intake lift
 * 
 * @return none
 */
void check_buttons() {  
    // bind the goal clamp to button 'A'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        clamp.toggle();
    }

    // bind temperature check to button 'B'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        output_temps();
    }

    // bind intake lift to button 'Y'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        intake_lift.toggle();
    }
}

/**
 * Performs a single check of the state of the buttons 'R1' and 'R2', 
 * which control the intake motor.
 * 
 * R1: Intake the ring
 * R2: Outtake the ring
 * 
 * @return none
 */
void check_intake() {
    if (controller.get_digital(DIGITAL_R1)) {
        intake.move_voltage(12000);
    } else if (controller.get_digital(DIGITAL_R2)) {
        intake.move_voltage(-6000);
    } else {
        intake.move_voltage(0);
    }
}

/**
 * Performs a single check of the state of the buttons 'L1' and 'L2', 
 * which control the arm mg.
 * 
 * L1: Raise the arm
 * L2: Lower the arm
 * 
 * @return none
 */
void check_arm() {
    if (controller.get_digital(DIGITAL_L1)) {
        arm.move_voltage(12000);
    } else if (controller.get_digital(DIGITAL_L2)) {
        arm.move_voltage(-12000);
    } else {
        arm.move_voltage(0);
    }
}

/*
float front_back = 0;
float left_right = 0;


void usercontrol()
{
    arm.setStopping(vex::hold);
    while (1)
    {

        
        front_back = (Controller.Axis3.position() > 0) ? sqrt((pow(Controller.Axis3.position(), 2) + pow(Controller.Axis4.position(), 2))) :
        -sqrt((pow(Controller.Axis3.position(), 2) + pow(Controller.Axis4.position(), 2)));
        // Calculate the front-back movement using joystick axes (Axis3 and Axis4 for a combination of movement)
        // Uses distance from 0, 0 through Pythagoreas theorem and enables movement based on semicircle

        left_right = (Controller.Axis1.position() > 0) ? sqrt((pow(Controller.Axis1.position(), 2) + pow(Controller.Axis2.position(), 2))) :
        -sqrt((pow(Controller.Axis1.position(), 2) + pow(Controller.Axis2.position(), 2)));
        // Calculate the front-back movement using joystick axes (Axis1 and Axis2 for a combination of movement)
        // Uses distance from 0, 0 through Pythagoreas theorem and enables movement based on semicircle

        left_drivetrain.spin(vex::forward, (((fabs(front_back) < 9 && front_back != 0) ? 9 * front_back : front_back) -
        ((fabs(left_right) < 9 && left_right != 0) ? 10 * left_right : left_right)) * 127/1000, vex::volt);

        right_drivetrain.spin(vex::forward, (((fabs(front_back) < 9 && front_back != 0) ? 9 * front_back : front_back) + 
        ((fabs(left_right) < 9 && left_right != 0) ? 10 * left_right : left_right)) * 127/1000, vex::volt);
        // If the absolute value of front_back is less than 9 (deadzone) and not zero, set front_back to 9 for friction
        // Apply a correction to left_right in similar fashion for small values.

        wait(10, vex::msec);
    }
}
*/