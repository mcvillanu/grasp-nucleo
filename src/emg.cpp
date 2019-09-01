/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#include "emg.h"
#include "Arduino.h" // is this possible ??

#define RESOLUTION_ADC 1023; // ??

Emg_signal::Emg_signal(int pin) {
    /* assign analog input pin to emg signal */
    this->pin = pin;
}

bool Emg_signal::peak_detected(float voltage) {
    this->emg_voltage();
    if (this->voltage > REF_VOLTAGE) {
        return true;
    }
    else {
        return false;
    }
}

void Emg_signal::emg_voltage() {
    int adc_value = analogRead(this->pin);
    float voltage = adc_value * 5 / RESOLUTION_ADC; // ??
    this->voltage = voltage;
}
