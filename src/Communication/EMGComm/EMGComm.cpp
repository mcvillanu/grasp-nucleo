/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#include "Communication/EMGComm/EMGComm.h"

EMG::EMG(int pin) : pin(pin) { /* assign analog input pin to emg signal */ }

bool EMG::peakDetected(float voltage) {
    //this->emg_voltage();
    if (voltage > REF_VOLTAGE) {
        return true;
    }
    else {
        return false;
    }
}

float EMG::EMGVoltage() {
    int ADCValue = analogRead(this->pin);
    return ((ADCValue * 5.0) / RESOLUTION_ADC); // ??
}
