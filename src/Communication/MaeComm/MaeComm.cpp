#include <Communication/MaeComm/MaeComm.h>



Motor::Motor(int const & channel, int const & fsrPin, MicroMaestro * const & maestro) : channel(channel), fsrPin(fsrPin), fsr(FSR(fsrPin)), maestro(maestro) {
    // this->servo.attach(pin);
}
void Motor::setup() {
    // this->servo.attach(this->pin);
    pinMode(this->channel, OUTPUT);
}
void Motor::moveTo(uint16_t const & position) {
    if (!fsr.exceededThreshold() || position<=currPos){
        currPos = position;
        // If brake is on, finger can only release
        // analogWrite(this->pin, position);
        maestro->setTarget(this->channel,position);
    } else {
        // TODO: communicate that the brake is on
    }
    
}
void Motor::setSpeed(uint16_t const & speed) {
    maestro->setSpeed(channel,speed);
}
void Motor::setAcceleration(uint16_t const & accel) {
    maestro->setAcceleration(channel,accel);
}
