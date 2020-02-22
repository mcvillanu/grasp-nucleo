#ifndef MOTOR_H
#define MOTOR_H
#include <fsr.h>
#include <vector>
#include <PololuMaestro.h>
using namespace std;
class Motor {
    public:
        /**
         * Default constructor for the motor. Sets up linear actuator on given pin.
         **/
        Motor(int channel, int fsrpin, MicroMaestro* maestro);

        void setup();

        /**
         * Moves the motor to the defined percentage along its arc.
         * 50 = 50%, 100 = 100%, etc.
         **/
        void move_to(uint16_t position);

        void setSpeed(uint16_t speed);
        void setAcceleration(uint16_t accel);
        void set_grip(int grip);
    private:
        int channel;
        int fsrpin;
        Fsr fsr = Fsr(fsrpin);
        uint16_t currPos; // current position
        MicroMaestro* maestro;
 
        
};
#endif