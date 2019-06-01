#ifndef MOTOR_H
#define MOTOR_H
#include <Servo.h>
class Motor {
    public:
        /**
         * Default constructor for the motor. Sets up linear actuator on given pin.
         **/
        Motor(int pin);

        /**
         * Moves the motor to the defined percentage along its arc.
         * 50 = 50%, 100 = 100%, etc.
         **/
        void move_to(int position);
    private:
        int pin;
        Servo servo;

};
#endif