#include "driver.h"
#include "pros/misc.h"

/**
 * Prints the temperatures of the left mg, right mg, and the intake motor
 * to the brain screen.
 * 
 * @return none
 */
void output_temps() {
    controller.print(0, 0, "i: %.0f a: %.0f", intake.get_temperature(), arm.get_temperature());
}

/**
 * Performs a single check of the buttons.
 * 
 * Y: Toggle the state of the clamp
 * B: Output the temperatures of the left mg, right mg, and intake (see output_temps())
 * A: Toggle the state of the intake lift
 * X: Puts the arm into position to intake a ring into it
 * 
 * @return none
 */
void check_buttons() {  
    // bind the goal clamp to button 'Y'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        clamp.toggle();
    }

    // bind temperature check to button 'B'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        output_temps();
        sweeper.toggle();
    }

    // bind intake lift to button 'A'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        intake_lift.toggle();
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        move_arm_to(22, 2000);
        arm.brake();
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
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intake.move_velocity(400);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intake.move_velocity(-400);
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
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        move_arm_up();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        move_arm_down();
    } else {
        stop_arm();
    }
}
