#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */
 

 void skills(void){
  Clam.set(false);
  //score on alliance goal
  intake.spin(fwd, 100, pct);
  wait(500, msec);
  intake.stop();
  chassis.drive_distance(4);
  //go for mobile goal 
  chassis.turn_to_angle(117);
  chassis.drive_distance(-19);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 12;
  Clam.set(true);
  wait(500, msec);
  //go for ring 1
  chassis.turn_to_angle(4);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(28);
  wait(1500, msec);
  // go for ring2
  chassis.turn_to_angle(252);
  //chassis.drive_max_voltage = 12;
  chassis.drive_distance(25);
  wait(300, msec);
  //go for ring 3
  chassis.turn_to_angle(178);
  wait(300, msec);
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(20);
  wait(1000, msec);
  //go for ring 4
  chassis.drive_distance(15);
  wait(1000, msec);
  //go for ring 5
  chassis.drive_distance(-15);
  chassis.turn_to_angle(271);
  chassis.drive_distance(15);
  wait(1000, msec);
  chassis.drive_distance(-15);
  //drop goal in positive
  chassis.turn_to_angle(40);
  chassis.drive_max_voltage = 10;
  chassis.drive_distance(-20);
  Clam.set(false);
  intake.stop();
  chassis.drive_distance(20);
  chassis.drive_max_voltage = 12;
  //go for mobile goal
  chassis.turn_to_angle(272);
  chassis.drive_distance(-60);
  wait(100, msec);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-15);
  chassis.drive_max_voltage = 10;
  Clam.set(true);
  wait(200, msec);
  //go for ring 1
  chassis.turn_to_angle(0);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(26);
  wait(1.5, sec);
  //go for ring 2
  chassis.turn_to_angle(91);
  chassis.drive_distance(33);
  wait(1, sec);
  //go for ring 3
  chassis.drive_distance(-4);
  chassis.turn_to_angle(184);
  chassis.drive_max_voltage = 6;
  //go for ring 4
  chassis.drive_distance(25);
  wait(1000, msec);
  chassis.drive_distance(17);
  wait(1000, msec);
//go for ring 5
  chassis.drive_distance(-15);
  chassis.turn_to_angle(91);
  chassis.drive_distance(15);
  wait(1000, msec);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(250);
  chassis.drive_distance(-25);
  Clam.set(false);
 }

 void left1(void){
  Clam.set(false);
  chassis.turn_to_angle(22);
  chassis.drive_distance(-24);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;
  Clam.set(true);
  wait(0.15, sec);
  intake.spin(fwd, 100, pct);
  wait(0.5, sec);
  intake.stop();
  //chassis.turn_max_voltage = 3;
  chassis.turn_to_angle(92);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(30);
  wait(1.2, sec);
  intake.stop();
  intake.spin(fwd, -100, pct);
  chassis.drive_distance(-30);
  intake.stop();
  //chassis.turn_to_angle(90);
  chassis.turn_to_angle(-110);
  chassis.drive_distance(9);
  Mop.set(true);
  ;
 }
 void left2(){
  chassis.drive_distance(-19);
  chassis.turn_to_angle(90);//hello
  chassis.drive_distance(-3);
  wait(500, msec);
  intake.spin(fwd, 100, pct);
  wait(1, sec);
  chassis.drive_distance(8);
  intake.stop();
  chassis.turn_to_angle(-128);
  chassis.drive_distance(-27);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-10);
  chassis.drive_max_voltage = 10;
  wait(100, msec);
  Clam.set(true);
  wait(300, msec);
  chassis.turn_to_angle(0);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(25);
  wait(2, sec);
  intake.stop();
  chassis.turn_to_angle(170);
  chassis.drive_max_voltage = 10;
  chassis.drive_distance(30);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(10);
  chassis.drive_max_voltage = 10;
  stork.spin(fwd, 100, pct);
  Mop.set(true);


 }

 void right2(){
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-3);
  wait(500, msec);
  intake.spin(fwd, 100, pct);
  wait(1, sec);
  chassis.drive_distance(8);
  intake.stop();
  chassis.turn_to_angle(125);
  chassis.drive_distance(-28);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-9);
  chassis.drive_max_voltage = 10;
  wait(100, msec);
  Clam.set(true);
  wait(300, msec);
  chassis.turn_to_angle(0);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(25);
  wait(2, sec);
  intake.stop();
  chassis.turn_to_angle(-140);
  chassis.drive_distance(16);
  Mop.set(true);


 }



 void right1(){
  Clam.set(false);
  chassis.turn_to_angle(22);
  chassis.drive_distance(-24);
  chassis.drive_max_voltage = 3;
  chassis.drive_distance(-9);
  chassis.drive_max_voltage = 10;
  Clam.set(true);
  wait(0.15, sec);
  intake.spin(fwd, 100, pct);
  wait(0.5, sec);
  intake.stop();
  //chassis.turn_max_voltage = 3;
  chassis.turn_to_angle(-92);
  intake.spin(fwd, 100, pct);
  chassis.drive_distance(30);
  wait(1.2, sec);
  intake.stop();
  intake.spin( fwd, -100, pct);
  chassis.drive_distance(-30);
  intake.stop();
  chassis.turn_to_angle(165);
  chassis.drive_distance(5.5);
  Mop.set(true);
  //stork.spin(fwd, 100, pct);


 
  
  

  // chassis.drive_distance(15.5);
  // intake.spin(fwd, 100, pct);
  // wait(0.5, sec);
  // intake.stop();
  // chassis.turn_to_angle(-120);


 }
void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.2, 0, 9.6, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .32, .0, 3, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 800);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(50);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(180);
 
  
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}