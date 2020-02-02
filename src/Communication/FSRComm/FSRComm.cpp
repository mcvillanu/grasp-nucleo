#include "Communication/FSRComm/FSRComm.h"



FSR::FSR(int pin) : pin(pin) {}
void FSR::setup() const {
    pinMode(this->pin, INPUT);
}
float FSR::getPSI() const {
    float voltage = (float) ((analogRead(this->pin) * COMMUNICATION::FSRCOMM::VCC) / 1023.0);
    return COMMUNICATION::FSRCOMM::CURVE_CONSTANT / COMMUNICATION::FSRCOMM::PULLDOWN_RESISTOR / (COMMUNICATION::FSRCOMM::VCC / voltage - 1);
}
bool FSR::exceededThreshold() const {
    return (getPSI() > COMMUNICATION::FSRCOMM::BRAKE_THRESHOLD);
}