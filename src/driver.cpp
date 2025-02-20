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
    }

    // bind intake lift to button 'A'
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        intake_lift.toggle();
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        raise_arm(200.0, 1000);
        //arm.move_absolute(217, 1000);
    }
}

void raise_arm(float target, float time_limit) {
    pros::Task task([=]() {
        lemlib::PID arm_pid(1, 0, 1, 50, true);
        float time = 0;

        float pos = arm.get_position();
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
        arm.brake();
    }
}
