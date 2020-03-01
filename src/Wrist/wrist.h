#ifndef WRIST_H
#define WRIST_H

#include <Arduino.h>
#include "DRV8834.h"
#include <Utilities/Constants.h>
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// Target RPM for cruise speed
#define RPM 120
// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000

class Wrist {
    public:
        Wrist();
        /**
         * Default constructor for the Wrist. Sets up stepper motor on.
         **/
        Wrist(int microsteps);

     

        void setup();

        /**
         * Moves the Wrist to the defined percentage along its arc.
         * 50 = 50%, 100 = 100%, etc.
         **/
        void rotate_by(int angle);

        unsigned poll();
        BasicStepperDriver stepper = BasicStepperDriver(MOTOR_STEPS, PINS::WRIST_DIR, PINS::WRIST_STEP);
    private:
        int microsteps = 1;

};
#endif