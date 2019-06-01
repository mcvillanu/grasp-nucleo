/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#include "emg.h"
#include "Arduino.h"

#define RESOLUTION_ADC 4023; // ??

Emg_signal::Emg_signal(int pin) {
    /* assign analog input pin to emg signal */
    this->pin = pin;
    
}

float Emg_signal::find_reference() {
    // find the reference point
    this->reference = reference;
}

bool Emg_signal::peak_detected() {
    if (this->voltage > this->reference) {
        return True
    }
    else {
        return False
    }
}

float Emg_signal::emg_voltage() {
    int pin = this->pin;
    int adc_value = analogRead(pin);
    float voltage = adc_value * 5 / RESOLUTION_ADC; // ??
    this->voltage = voltage;
    return voltage;
}
