#include "utility"

using namespace vex;
using namespace std;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern controller Controller1;
extern motor_group intake;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor_group LeftDriveSmart;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor_group RightDriveSmart;
extern motor intake1;
extern motor intake2;
extern motor stork;
extern rotation rotationSensor;
extern digital_out Clam;
extern digital_out Mop;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
void togglepiston();
void bogglepiston();
