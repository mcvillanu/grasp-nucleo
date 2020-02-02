/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
*/

#ifndef EMGCOMM_H
#define EMGCOMM_H

#include <CoAmpCAN.h>
#include <Arduino.h>
#include <Utilities/Constants.h>



class EMG {
    private:
        int pin;
        float voltage;
        bool flex;
        int arrayVoltage[1000]; /* save last 100 values for something, need something to reference the start ?? */

    public:
        EMG(int pin);
        bool peakDetected(float voltage);
        float EMGVoltage();
        void EMGLoop();
};

#endif