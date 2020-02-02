#ifndef MAECOMM_H
#define MAECOMM_H

#include <Communication/FSRComm/FSRComm.h>
#include <PololuMaestro.h>
#include <Arduino.h>
#include <Communication/PiComm/PiComm.h>



class Motor {
    private:
        int channel;
        int fsrPin;
        FSR fsr;
        uint16_t currPos;
        MicroMaestro * maestro;

    public: 
        Motor(int const & channel, int const & fsrpin, MicroMaestro * const & maestro);

        void setup();
        void moveTo(uint16_t const & position);

        void setSpeed(uint16_t const & speed);
        void setAcceleration(uint16_t const & accel);
};

#endif