using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor Intake;
extern motor Ramp;
extern motor Push_ramp1;
extern motor Push_ramp2;
extern digital_out MogoMech1;
extern digital_out MogoMech2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
