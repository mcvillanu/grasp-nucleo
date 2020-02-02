#include "Communication/EMGComm/EMGComm.h"

EMG::EMG(int pin) : pin(pin) {}
bool EMG::peakDetected(float voltage) {
    return (voltage > COMMUNICATION::EMGCOMM::REFERENCE_VOLTAGE);
}
float EMG::EMGVoltage() {
    int ADCValue = analogRead(this->pin);
    return ((ADCValue * CONSTANTS::VCC) / COMMUNICATION::EMGCOMM::RESOLUTION_ADC); // ??
}
