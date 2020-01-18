/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
*/

#ifndef EMG_H
#define EMG_H

#define REF_VOLTAGE 1.2

#include <CoAmpCAN.h>

class Emg_signal {
    public:
        /* Default constructor for EMG input, initialize input PIN */
        Emg_signal(int pin);
    

        /* returns a flag that means a flex has occured*/
        bool peak_detected(float voltage);

        float emg_voltage();

        void emg_loop();
    private:
        int pin;
        float voltage;
        bool flex;
        int array_voltage[1000]; /* save last 100 values for something, need something to reference the start ?? */
};
#endif