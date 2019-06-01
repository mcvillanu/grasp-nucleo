/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#ifndef EMG_SIG
#define EMG_SIG
class Emg_signal {
    public:
        /* Default constructor for EMG input */
        Emg_signal(int pin);
        
        /* find initial value for relaxed hand */
        float find_reference();

        /* returns a flag that means a flex has occured*/
        bool peak_detected(int voltage);

        /* returns the value of the voltage read from the pin */
        int emg_voltage(void);
    private:
        int pin;
        int reference;
        float voltage;
        int array_voltage[1000]; /* save last 100 values for something, need something to reference the start */
};
#endif