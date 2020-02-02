#ifndef MAECOMM_H
#define MAECOMM_H

#include <fsr.h>
#include <PololuMaestro.h>
#include <Arduino.h>
#include <PiComm.h>



class Motor {
    private:
        int channel;
        int fsrpin;
        Fsr fsr = Fsr(fsrpin);
        uint16_t currPos;
        MicroMaestro * maestro;

    public:
        /**
         * Default constructor for the motor. Sets up linear actuator on given pin.
         **/
        Motor(int const & channel, int const & fsrpin, MicroMaestro * const & maestro);

        void setup();

        /**
         * Moves the motor to the defined percentage along its arc.
         * 50 = 50%, 100 = 100%, etc.
         **/
        void move_to(uint16_t position);

        void setSpeed(uint16_t speed);
        void setAcceleration(uint16_t accel);
};

#endif