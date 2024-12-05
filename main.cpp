/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
bool MogoMechsActive = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
// bool intake_ramp = false;
// bool intake_ramp1 = false;

// void IntakeRamp(void) {
//   intake_ramp = !intake_ramp;
//   if(intake_ramp == true) {
//     Ramp.spin(reverse, 100, pct);  // Spin intake motor forward at full speed
//     Intake.spin(reverse, 100, pct);
//   }
// }

// void IntakeRamp1(void) {
//   intake_ramp1 = !intake_ramp1;
//   if(intake_ramp1 == true) {
//     Ramp.spin(forward, 100, pct);  // Spin intake motor forward at full speed
//     Intake.spin(forward, 100, pct); 
//   }  

// }
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  //Plan: 
  // ..........................................................................

  //left side
  // Drivetrain.setDriveVelocity(75, percent);  // Set the drivetrain speed
  // Drivetrain.driveFor(reverse, 20, inches);   // Drive forward for 24 inches
  // Drivetrain.stop(brakeType::brake);
  // wait(1, sec);
  // MogoMech.set(false);
  // MogoMech.set(true);
  // wait(1, sec);
  // Drivetrain.driveFor(forward, 6, inches);
  // Drivetrain.stop(brakeType::brake);
  // wait(1, sec);
  // Intake.spin(reverse, 100, pct);
  // Ramp.spin(reverse, 80, pct);
  // wait(1, sec);
  // Drivetrain.turnFor(right, 90, degrees);
  // wait(1, sec);
  // Drivetrain.driveFor(forward, 22, inches);
  // Drivetrain.stop(brakeType::brake);
  // wait(1, sec);
  // Intake.spin(reverse, 100, pct);
  // Ramp.spin(reverse, 80, pct);
  // wait(1, sec);
  // Drivetrain.driveFor(forward, 8, inches);
  // Drivetrain.stop(brakeType::brake);

  //right side
  //Drivetrain.setDriveVelocity(75, percent);  // Set the drivetrain speed
  //Drivetrain.driveFor(forward, 30, inches);   // Drive forward for 24 inches
  //Drivetrain.stop(brakeType::brake);
  //wait(1, sec);
  //MogoMech.set(true);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 6, inches);
  //Drivetrain.stop(brakeType::brake);
  //Intake.spin(reverse, 100, pct);
  //Ramp.spin(forward, 80, pct);
  //wait(1, sec);
  //wait(1, sec);
  //Drivetrain.turnFor(left, 90, degrees);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 22, inches);
  //Drivetrain.stop(brakeType::brake);
  //wait(1, sec);
  //Intake.spin(reverse, 100, pct);
  //Ramp.spin(forward, 80, pct);
  //wait(1, sec);
  //Drivetrain.driveFor(forward, 8, inches);
  //Drivetrain.stop(brakeType::brake);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool intakeRampReverseToggle = false; // Track reverse motion for X button
bool intakeRampForwardToggle = false; // Track forward motion for Y button


void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    if(Controller1.ButtonA.pressing()) {
      while(Controller1.ButtonA.pressing()) {
        wait(10, msec);
      }
      MogoMechsActive = !MogoMechsActive;
      MogoMech1.set(MogoMechsActive);
      MogoMech2.set(MogoMechsActive);
      }
    if (Controller1.ButtonX.pressing()) {
      // Wait until the button is released to prevent multiple toggles
      while (Controller1.ButtonX.pressing()) {
        wait(10, msec);
      }
      intakeRampReverseToggle = !intakeRampReverseToggle; // Flip the reverse toggle

      // If reverse toggle is active, start reverse motion; otherwise, stop
      if (intakeRampReverseToggle) {
        Ramp.spin(reverse, 70, pct);
        Intake.spin(reverse, 70, pct);
        intakeRampForwardToggle = false; // Ensure forward motion is off
      } else {
        Ramp.stop(brakeType::brake);
        Intake.stop(brakeType::brake);
      }
    }

    // Toggle forward motion on Y button press
    if (Controller1.ButtonY.pressing()) {
      // Wait until the button is released to prevent multiple toggles
      while (Controller1.ButtonY.pressing()) {
        wait(10, msec);
      }
      intakeRampForwardToggle = !intakeRampForwardToggle; // Flip the forward toggle

      // If forward toggle is active, start forward motion; otherwise, stop
      if (intakeRampForwardToggle) {
        Ramp.spin(forward, 50, pct);
        Intake.spin(forward, 50, pct);
        intakeRampReverseToggle = false; // Ensure reverse motion is off
      } else {
        Ramp.stop(brakeType::brake);
        Intake.stop(brakeType::brake);
      }
    }

    if (Controller1.ButtonRight.pressing()) {
      while (Controller1.ButtonRight.pressing()) {
        Push_ramp1.spin(forward, 50, pct);
        Push_ramp2.spin(forward, 50, pct);
      }

    // if(Controller1.ButtonUp.pressing()) {
    //   Intake.spin(forward, 100, pct);  // Spin intake motor forward at full speed
    //   }   
    // else if(Controller1.ButtonDown.pressing()) {
    //   Intake.spin(reverse, 100, pct);  // Spin intake motor in reverse at full speed
    //   }
    // else {
    //   Intake.stop(brakeType::brake);   // Stop the intake motor when no button is pressed
    //   }
    // if(Controller1.ButtonLeft.pressing()) {
    //   Ramp.spin(forward, 100, pct);  // Spin intake motor forward at full speed
    //   }   
    // else if(Controller1.ButtonRight.pressing()) {
    //   Ramp.spin(reverse, 100, pct);  // Spin intake motor in reverse at full speed
    //   }
    // else {
    //   Ramp.stop(brakeType::brake);   // Stop the intake motor when no button is pressed
    //   }
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    }
  }
    


    
  



    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Drivetrain.setDriveVelocity(5, percent);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
