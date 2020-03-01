#include <Communication/EMGComm/EMGComm.h>

EMG::EMG(int pin) : BaseComm::Base(pin) {}
void EMG::setup() {
    pinMode(this->pin,INPUT);
}
bool const EMG::peakDetected(float const & voltage) const {
    return (voltage > COMMUNICATION::EMGCOMM::REFERENCE_VOLTAGE);
}
float const EMG::EMGVoltage() const {
    int ADCValue = analogRead(this->pin);
    return ((ADCValue * CONSTANTS::VCC) / COMMUNICATION::EMGCOMM::RESOLUTION_ADC); // ??
}
void EMG::EMGLoop() const {
    // TODO
}