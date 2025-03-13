#include "vex.h"

using namespace vex;

competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

    // Pick your drive setup from the list below:
    // ZERO_TRACKER_NO_ODOM
    // ZERO_TRACKER_ODOM
    // TANK_ONE_FORWARD_ENCODER
    // TANK_ONE_FORWARD_ROTATION
    // TANK_ONE_SIDEWAYS_ENCODER
    // TANK_ONE_SIDEWAYS_ROTATION
    // TANK_TWO_ENCODER
    // TANK_TWO_ROTATION
    // HOLONOMIC_TWO_ENCODER
    // HOLONOMIC_TWO_ROTATION
    //
    // Write it here:
    ZERO_TRACKER_NO_ODOM,

    // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
    // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

    // Left Motors:
    motor_group(leftMotorA, leftMotorB, leftMotorC),

    // Right Motors:
    motor_group(rightMotorA, rightMotorB, rightMotorC),

    // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
    PORT13,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // External ratio, must be in decimal, in the format of input teeth/output teeth.
    // If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
    // If the motor drives the wheel directly, this value is 1:
    0.75,

    // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
    // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
    360,

    /*---------------------------------------------------------------------------*/
    /*                                  PAUSE!                                   */
    /*                                                                           */
    /*  The rest of the drive constructor is for robots using POSITION TRACKING. */
    /*  If you are not using position tracking, leave the rest of the values as  */
    /*  they are.                                                                */
    /*---------------------------------------------------------------------------*/

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

    // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
    // LF:      //RF:
    PORT1, -PORT2,

    // LB:      //RB:
    PORT3, -PORT4,

    // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
    // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
    // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
    3,

    // Input the Forward Tracker diameter (reverse it to make the direction switch):
    -2.75,

    // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
    // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
    // This distance is in inches:
    -2,

    // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
    1,

    // Sideways tracker diameter (reverse to make the direction switch):
    -2.75,

    // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
    5.5

);

int current_auton_selection = 0;
bool auto_started = false;

int targetValueLB = 0;

void controlMotor()
{
  double encoderValue = rotationSensor.position(deg);
  if (encoderValue > 350)
    stork.spin(fwd, 50, pct);
  else
  {
    double output = (67 * (atan(0.025 * (targetValueLB - encoderValue))));
    stork.spin(fwd, output, pct);
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(output);
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print(encoderValue);
  }
}

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  while (!auto_started)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch (current_auton_selection)
    {
    case 0:
      Brain.Screen.printAt(5, 140, "Auton 1");
      break;
    case 1:
      Brain.Screen.printAt(5, 140, "Auton 2");
      break;
    case 2:
      Brain.Screen.printAt(5, 140, "Auton 3");
      break;
    case 3:
      Brain.Screen.printAt(5, 140, "Auton 4");
      break;
    case 4:
      Brain.Screen.printAt(5, 140, "Auton 5");
      break;
    case 5:
      Brain.Screen.printAt(5, 140, "Auton 6");
      break;
    case 6:
      Brain.Screen.printAt(5, 140, "Auton 7");
      break;
    case 7:
      Brain.Screen.printAt(5, 140, "Auton 8");
      break;
    }
    if (Brain.Screen.pressing())
    {
      while (Brain.Screen.pressing())
      {
      }
      current_auton_selection++;
    }
    else if (current_auton_selection == 8)
    {
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

// void skills(void){
//   // // Drivetrain.setDriveVelocity(75, percent);
//   // // Drivetrain.driveFor(reverse, 8, inches);
//   // // wait(1,sec);
//   // // Drivetrain.driveFor(reverse, 1.5, inches);
//   // // Clam.set(true);
//   // // Drivetrain.setDriveVelocity(100, percent);
//   // // Drivetrain.turnFor(vex::left, 105, deg);
//   // // intake.spin(fwd);
//   // // Drivetrain.driveFor(fwd, 13, inches);
//   // // Drivetrain.driveFor(fwd, 3, inches);
//   // // wait(1, sec);
//   // // Drivetrain.turnFor(vex::right, 15, deg);
//   // // Drivetrain.driveFor(fwd, 8, inches);
//   // chassis.setDriveVelocity(50, percent);
//   // Drivetrain.driveFor(vex::directionType::rev, 10.9, inches);
//   // //wait(1.5, sec);
//   // Drivetrain.driveFor(vex::directionType::rev, 0.4, inches);
//   // Clam.set(true);
//   // intake.spin(vex::directionType::rev);
//   // wait(0.2, sec);
//   // intake.stop();
//   // //Drivetrain.driveFor(fwd, 10, inches);
//   // //intake.spin(fwd);
//   // //wait(1, sec);
//   // Drivetrain.setDriveVelocity(100, percent);
//   // Drivetrain.turnFor(vex::right, 150, deg);
//   // Drivetrain.driveFor(fwd, 11, inches);
//   // intake.spin(fwd);
//   // wait(1.5, sec);
//   // intake.stop();
//   // intake.spin(vex::directionType::rev);
//   // wait(0.5, sec);
//   // intake.stop();
//   // intake.spin(fwd);
//   // Drivetrain.driveFor(fwd, 4, inches);
//   // Drivetrain.driveFor(fwd, 15.5, inches);
//   // //Drivetrain.driveFor(fwd, 5, inches);
//   // Drivetrain.turnFor(vex::left, 110, deg);
//   // Drivetrain.driveFor(fwd, 26, inches);
//   // //wait(1, sec);
//   // Drivetrain.turnFor(vex::left, 70, deg);
//   // intake.stop();
//   // intake.spin(vex::directionType::rev);
//   // wait(0.5, sec);
//   // intake.stop();
//   // intake.spin(fwd);
//   // Drivetrain.driveFor(fwd, 10, inches);
//   // wait(1, sec);
//   // intake.stop();
//   // intake.spin(vex::directionType::rev);
//   // wait(0.2, sec);
//   // intake.spin(fwd);
//   // Drivetrain.driveFor(fwd, 14, inches);
//   // intake.spin(vex::directionType::rev);
//   // wait(0.5, sec);
//   // intake.stop();
//   // Drivetrain.turnFor(vex:: right, 225, deg);
//   // Drivetrain.driveFor(vex::directionType::rev, 12, inches);
//   // //Drivetrain.driveFor(fwd, 24, inches);
//   // //Drivetrain.turnFor(vex::left, 30, deg);
//   // //Drivetrain.driveFor(fwd, 5, inches);
//   // //Drivetrain.turnFor(vex::right, 180, deg);
// }

// void right1(void){
// //   Clam.set(true);
// //   Drivetrain.setDriveVelocity(75, percent);
// //   //Drivetrain.turnFor(left, 25, deg);
// //   //Drivetrain.driveFor(reverse, 25, inches);
// //   //wait(1.5, sec);
// //  // Drivetrain.driveFor(reverse, 0.4, inches);
// //   // Clam.set(true);
// //   // wait(1, sec);
// //   // intake.spin(fwd);
// //   // wait(1, sec);
// //   // intake.stop();
// //   Drivetrain.driveFor(vex::directionType::rev, 25, inches);
// //   wait(0.5, sec);
// //   Drivetrain.setDriveVelocity(50, percent);
// //   Drivetrain.driveFor(vex::directionType::rev, 6, inches);
// //   Clam.set(false);
// //   wait(1, sec);
// //   intake.spin(fwd);
// //   wait(1, sec);
// //   intake.stop();
// //   intake.spin(vex::directionType::rev);
// //   wait(1,sec);
// //   intake.stop();
// //   Drivetrain.setDriveVelocity(100, percent);
// //   Drivetrain.turnFor(vex::left, 97, deg);
// //   Drivetrain.driveFor(fwd, 15.5, inches);
// //   intake.spin(fwd);
// //   Drivetrain.driveFor(fwd, 4, inches);
// //   wait(1.4, sec);
// //   intake.stop();
// //   intake.spin(vex::directionType::rev);
// //   wait(0.5, sec);
// //   intake.stop();
// //   Drivetrain.turnFor(vex::left, 150, deg);
// //   Drivetrain.driveFor(fwd, 28, inches);
// //   //Drivetrain.turnFor(vex::right, 5, deg);
// //   //Drivetrain.driveFor(reverse, 33.2, inches);
// //   //Drivetrain.turnFor(vex::left, 82, deg);
// }

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void)
{
  auto_started = true;
  switch (current_auton_selection)
  {
  case 0:
    drive_test();
    break;
  case 1:
    drive_test();
    break;
  case 2:
    turn_test();
    break;
  case 3:
    swing_test();
    break;
  case 4:
    full_test();
    break;
  case 5:
    odom_test();
    break;
  case 6:
    tank_odom_test();
    break;
  case 7:
    holonomic_odom_test();
    break;
  case 8:
    left1();
    break;
  case 9:
    right1();
    break;
  case 10:
    right2();
    break;
  case 11:
    left2();
    break;
    case 12:
     skills();
     break;
  }
}

// void autonomous(void){
//   // //Drivetrain.setTurnConstant(.94);
//   // //Drivetrain.setTurnVelocity(100, percent);
//   // //Drivetrain.setDriveVelocity(100, percent);
//   // //intake.setVelocity(100, pct);
//   //Drivetrain.driveFor(fwd, 90, inches);
//   // //Drivetrain.setHeading(90, degrees);
//   //intake.spin(reverse);
//   //wait(500, msec);
//   //intake.stop();
//   //autonred1();
//   left1();
//   // Drivetrain.driveFor(reverse, 29, inches);
//   // Drivetrain.setDriveVelocity(75, percent);
//   // Drivetrain.driveFor(reverse, 2, inches);
//   //wait(100, msec);
//     //Drivetrain.turnFor(right,75, deg);
//   //intake.spin(fwd);
//   //Drivetrain.driveFor(fwd, 12, inches);
//   //getTrig(10.5,1.6);
// }

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
const int LBValueRest = 10;
const int LBValueTake = 45;
const int LBValueExtend = 190;
const int topdscr = 177;
const int botdscr = 187;

bool Flag = false;

int IntakeLBControl()
{

  while (1)
  {
    if (Controller1.ButtonUp.pressing() /*&& Controller1.ButtonR2.pressing()*/)
    {
      Flag = false;
      intake.spin(fwd, -100, pct);
    }

    else if (Controller1.ButtonR1.pressing())
    {
      Flag = true;
      intake1.spin(fwd, 100, pct);
      intake2.spin(fwd, 100, pct);
      targetValueLB = LBValueRest;
    }

    else if (Controller1.ButtonR2.pressing())
    {
      Flag = true;
      intake.spin(fwd, 100, pct);
      targetValueLB = LBValueTake;
    }
    else if (Controller1.ButtonLeft.pressing())
    {
      Flag = true;
      targetValueLB = topdscr;
    }
    else if (Controller1.ButtonDown.pressing())
    {
      Flag = true;
      targetValueLB = botdscr;
    }
    else
    {
      intake1.stop(hold);
      intake2.stop(hold);
    }

    if (Controller1.ButtonL1.pressing())
    {
      Flag = true;
      targetValueLB = LBValueExtend;
      intake.spin(fwd, -20, pct);
    }
    // if(Controller1.ButtonL1.pressing())
    //{
    // Flag = false;
    // stork.spin(fwd, 100, pct);
    //}

    if ((Controller1.ButtonL1.pressing() || Controller1.ButtonR1.pressing() || Controller1.ButtonR2.pressing() || Controller1.ButtonLeft.pressing() || Controller1.ButtonDown.pressing()) && Flag)
    {
      controlMotor();
    }

    else
    {
      if (Controller1.ButtonL2.pressing())
      {
        Flag = false;
        stork.spin(fwd, -100, pct);
      }
      else
        stork.stop(hold);
    }
    wait(20, msec);
  }

  return 0;
}

void usercontrol(void)
{
  bool ClamBState = false;
  bool MopBState = false;
  vex::task LBInt(IntakeLBControl);
  // User control code here, inside the loop
  while (1)
  {

    int Lvel = Controller1.Axis3.position() + Controller1.Axis1.position();
    int Rvel = Controller1.Axis3.position() - Controller1.Axis1.position();

    if (abs(Lvel) > 20)
      LeftDriveSmart.spin(fwd, Lvel, pct);

    else
      LeftDriveSmart.stop();

    if (abs(Rvel) > 20)
      RightDriveSmart.spin(fwd, Rvel, pct);

    else
      RightDriveSmart.stop();

    if (Controller1.ButtonA.pressing())
    {
      if (!ClamBState)
      {
        ClamBState = true;
        togglepiston();
      }
    }
    else
      ClamBState = false;

    if (Controller1.ButtonB.pressing())
    {
      if (!MopBState)
        ;
      {
        MopBState = true;
        bogglepiston();
      }
    }
    else
      MopBState = false;

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(skills);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
