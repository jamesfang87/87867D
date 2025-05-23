#include "robot.h"
#include "pros/rotation.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motors({-1, -2, 3}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({10, -8, 9}, pros::MotorGearset::blue);
lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                            &right_motors, // right motor group
                            14, // track width
                            lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                            480, // chassis rpm
                            2 // horizontal drift is 2 (for now)
);

pros::Motor intake(4, pros::MotorGearset::blue);

pros::MotorGroup arm({11, -19}, pros::MotorGearset::green);
pros::Rotation arm_encoder(18);

pros::Imu imu(17);

pros::Rotation horizontal_encoder(5);
pros::Rotation vertical_encoder(13);

// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -4.75);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -1.625);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                        nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                        &horizontal_tracking_wheel, // horizontal tracking wheel 1
                        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                        &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(4.3, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            8, // derivative gain (kD)
                                            0, // anti windup
                                            0, // small error range, in inches
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in inches
                                            0, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(1.7, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            12.3, // derivative gain (kD)
                                            0, // anti windup
                                            0, // small error range, in degrees
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in degrees
                                            0, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                    lateral_controller, // lateral PID settings
                    angular_controller, // angular PID settings
                    sensors // odometry sensors
);

// Pneumatics
pros::adi::Pneumatics intake_lift(1, false);
pros::adi::Pneumatics clamp(2, true);
pros::adi::Pneumatics sweeper(3, false);
