/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
*/

#ifndef EMGCOMM_H
#define EMGCOMM_H

#include <CoAmpCAN.h>
#include <Arduino.h>
#include <Utilities/Constants.h>
#include <Communication/BaseComm/BaseComm.h>



class EMG : Base {
    private:
        float voltage;
        bool flex;
        int arrayVoltage[1000]; /* save last 100 values for something, need something to reference the start ?? */

    public:
        EMG(int pin);
        
        virtual void setup();

        bool const peakDetected(float const & voltage) const;
        float const EMGVoltage() const;
        void EMGLoop() const;
};

#endif