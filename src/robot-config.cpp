#include "vex.h"
#include "utility"
using namespace std;

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors  
motor leftMotorA = motor(PORT16, ratio6_1, true);
motor leftMotorB = motor(PORT17, ratio6_1, true);
motor leftMotorC = motor(PORT20, ratio6_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT19, ratio6_1, false);
motor rightMotorB = motor(PORT14, ratio6_1, false);
motor rightMotorC = motor(PORT15, ratio6_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
inertial DrivetrainInertial = inertial(PORT6);
// smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 257.97, 320, 40, mm, .75);
controller Controller1 = controller(primary);
motor intake1 = motor(PORT2, ratio6_1, true);
motor intake2 = motor(PORT21, ratio18_1, true);
motor stork = motor(PORT9, ratio18_1, false);
rotation rotationSensor = rotation(PORT4, true);

motor_group intake = motor_group(intake1, intake2); 
digital_out Clam = digital_out(Brain.ThreeWirePort.A);
digital_out Mop = digital_out(Brain.ThreeWirePort.B);

//motor_group Drivetrain = motor_group(LeftDriveSmart, RightDriveSmart);

void togglepiston();
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1RightShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;




// define a task that will handle monitoring inputs from Controller1

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */

void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}


bool ClamBState = false;
bool MopBState = false;

void togglepiston()
{

  if (Clam.value())
    Clam.set(false);
  else
    Clam.set(true);
  
}

void bogglepiston(){
  if (Mop.value())
    Mop.set(false);
  else
    Mop.set(true);
  wait(250, msec);
}