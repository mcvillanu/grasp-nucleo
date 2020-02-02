#ifndef FSRCOMM_H
#define FSRCOMM_H

#include <Arduino.h>
#include <Utilities/Constants.h>



class FSR {
    private:
        int pin;

    public:
        FSR(int pin);

        void  setup             () const;
        float getPSI            () const;
        bool  exceededThreshold () const;
};

#endif