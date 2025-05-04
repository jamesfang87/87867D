#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rotation.hpp"

#ifndef ROBOT_H
#define ROBOT_H
extern pros::Controller controller;

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;

extern pros::Motor intake;

extern pros::MotorGroup arm;
extern pros::Rotation arm_encoder;

extern pros::Imu imu;
extern pros::Rotation horizontal_encoder;
extern pros::Rotation vertical_encoder;

extern lemlib::TrackingWheel horizontal_tracking_wheel;
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
extern pros::adi::Pneumatics sweeper;

#endif