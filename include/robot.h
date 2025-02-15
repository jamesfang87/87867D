#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

/*
class Robot {
private:
    pros::MotorGroup left_mg, right_mg;
    pros::Imu imu;
    pros::Rotation horizontal_encoder, vertical_encoder;

public:
    Robot();
};

*/

#ifndef ROBOT_H
#define ROBOT_H
extern pros::Controller controller;

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;

extern pros::Motor intake;

extern pros::MotorGroup arm;

extern pros::Imu imu;
extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;

// horizontal tracking wheel
extern lemlib::TrackingWheel horizontal_tracking_wheel;
// vertical tracking wheel
extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::OdomSensors sensors;

// lateral PID controller
extern lemlib::ControllerSettings lateral_controller;

// angular PID controller
extern lemlib::ControllerSettings angular_controller;

// create the chassis
extern lemlib::Chassis chassis;

// Pneumatics
extern pros::adi::Pneumatics clamp;
extern pros::adi::Pneumatics intake_lift;

class Intake {
public:
    void run_intake();
    void run_outtake();
    void stop();
};

#endif