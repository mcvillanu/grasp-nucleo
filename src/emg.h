/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#ifndef EMG_H
#define EMG_H

#include ""


class Emg_signal {
    public:
        /* Default constructor for EMG input, initialize input PIN */
        Emg_signal(int pin);
        
        /* find initial value for relaxed hand */
        float find_reference();

        /* returns a flag that means a flex has occured*/
        bool peak_detected(int voltage);

        /* returns the value of the voltage read from the pin */
        int emg_voltage(void);

        void emg_loop(void);
    private:
        int pin;
        int reference;
        float voltage;
        bool flex;
        int array_voltage[1000]; /* save last 100 values for something, need something to reference the start ?? */
};
#endif