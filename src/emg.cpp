/* EMG Software
 * Written: June 1, 2019
 * Purpose: Detect when the EMG signal voltage is above a certain threshold and throw a flag
 * WIP cuz idk c++
*/

#include "emg.h"
#include "Arduino.h" // is this possible ??

#define RESOLUTION_ADC 4023; // ??

Emg_signal::Emg_signal(int pin) {
    /* assign analog input pin to emg signal */
    this->pin = pin;
}

float Emg_signal::find_reference() {
    // find the reference point
    initial_voltage = this->emg_voltage();
    reference = initial_voltage * 2; // some factor of the resting voltage should be the peak or 
                                    // maybe initalize some sort of setup where you flex multiple times to get the 
                                    // approximate value or have a debug mode
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

void Emg_signal::emg_voltage() {
    int adc_value = analogRead(this->pin);
    float voltage = adc_value * 5 / RESOLUTION_ADC; // ??
    this->voltage = voltage;
}

void EMG_signal::emg_loop() {
    this->find_reference();
    while(1) {
        this->emg_voltage();
        this->flex = peak_detected();
    }
}
