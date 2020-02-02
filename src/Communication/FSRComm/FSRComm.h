#ifndef FSRCOMM_H
#define FSRCOMM_H

#include <Arduino.h>
#include <Utilities/Constants.h>



class FSR {
    private:
        int const pin;

    public:
        FSR(int const pin);

        void        setup             () const;
        float const getPSI            () const;
        int   const getPin            () const;
        bool  const exceededThreshold () const;
};

#endif