/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
*/

#ifndef EMGCOMM_H
#define EMGCOMM_H

#include <CoAmpCAN.h>
#include <Arduino.h>



#define REF_VOLTAGE 1.2
#define RESOLUTION_ADC 1024.0; // ??

class EMG {
    private:
        int pin;
        float voltage;
        bool flex;
        int arrayVoltage[1000]; /* save last 100 values for something, need something to reference the start ?? */

    public:
        /* Default constructor for EMG input, initialize input PIN */
        EMG(int pin);
        /* returns a flag that means a flex has occured*/
        bool peakDetected(float voltage);
        float EMGVoltage();
        void EMGLoop();
};

#endif