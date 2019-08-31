#ifndef WRIST_H
#define WRIST_H
#include <Arduino.h>
#include "DRV8834.h"
#include "constants.h"
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
// Target RPM for cruise speed
#define RPM 120
// Acceleration and deceleration values are always in FULL steps / s^2
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000

class Wrist {
    public:
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
        DRV8834 stepper = DRV8834(MOTOR_STEPS, dir_pin, step_pin, micro0, micro1);
    private:
        int step_pin = PINS::WRIST_STEP;
        int dir_pin = PINS::WRIST_DIR;
        int micro0 = PINS::WRIST_M0;
        int micro1 = PINS::WRIST_M1;
        int microsteps;

};
#endif