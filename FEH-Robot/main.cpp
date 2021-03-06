#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"

int main(void)
{
    // Competition run
    float ddrY = startRun();

    // Drives to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 45);
    checkHeading(270);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 16.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 85);
    checkHeading(180);

    // Drives up pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 5.5, RAMP_MOTOR_PERCENT, BACKWARD, 25.0);
    driveArcDistance(RAMP_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 13.0);

    // Drives to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 110);
    checkHeading(128);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.75);
    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 12.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 27.5);
    checkHeading(180);
    driveStraightTime(40.0, FORWARD, 0.5);

    //Drops token
    dropToken();

    // Aligns with wall before foosball (not corner)
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 0.75);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 2.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+1.0, FAST_MOTOR_PERCENT, BACKWARD, 6.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+3.0, FAST_MOTOR_PERCENT, BACKWARD, 3.25);
    driveStraightTime(40.0, BACKWARD, 1.0);

    // Drives off of wall
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
    checkHeading(90);

    // Lines up with stairs of foosball ramp
    turn(TURN_MOTOR_PERCENT, LEFT, 89);
    checkHeading(180);
    driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 2.5);

    // Drives to foosball counters
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 6.25);
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 130);
    driveStraightTime(40.0, BACKWARD, 0.6);

    // Slides foosball counters
    slideFoosball();

    // Drives to claw lever
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 1.0);

    // Flips claw lever
    flipLever();

    // Drives back to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 6.25);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 13.0);
    checkHeading(0);

    // Drives down pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 15.5);
    driveArcDistance(DEFAULT_MOTOR_PERCENT + 5.0, FAST_MOTOR_PERCENT, BACKWARD, 16.75);

    // Drives to DDR
    turn(TURN_MOTOR_PERCENT, RIGHT, 70);
    checkHeading(270);
    driveStraightTime(40.0, FORWARD, 1.0);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
    checkHeading(180);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);
    checkLocationY(ddrY);
    Sleep(0.25);

    // Plays Dance Dance Robot
    playDDR();

    // Drives to final button
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 10.0);
    turn(FAST_MOTOR_PERCENT, LEFT, 38);

    // Presses final button
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 1.25);

    LCD.WriteLine("Done!");
    return 0;


}
