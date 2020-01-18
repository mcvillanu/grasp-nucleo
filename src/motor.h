#ifndef MOTOR_H
#define MOTOR_H
#include <fsr.h>
class Motor {
    public:
        /**
         * Default constructor for the motor. Sets up linear actuator on given pin.
         **/
        Motor(int pin, int fsrpin);

        void setup();

        /**
         * Moves the motor to the defined percentage along its arc.
         * 50 = 50%, 100 = 100%, etc.
         **/
        void move_to(int position);
    private:
        int pin;
        int fsrpin;
        Fsr fsr = Fsr(fsrpin);
        int currPos; // current position

};
#endif