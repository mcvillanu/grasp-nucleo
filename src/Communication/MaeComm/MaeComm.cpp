#include <MaeComm.h>


Motor::Motor(int const & channel, int const & fsrpin, MicroMaestro * const & maestro) : channel(channel), fsrpin(fsrpin), maestro(maestro) {
    // this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::setup() {
    // this->servo.attach(this->pin);
    pinMode(this->channel, OUTPUT);
}

void Motor::move_to(uint16_t position) {
    if (!fsr.safetyBrake() || position<=currPos){
        currPos = position;
        // If brake is on, finger can only release
        //analogWrite(this->pin, position);
        maestro->setTarget(this->channel,position);
    } else {
        // TODO: communicate that the brake is on
    }
    
}

void Motor::setSpeed(uint16_t speed){
    maestro->setSpeed(channel,speed);
}

void Motor::setAcceleration(uint16_t accel) {
    maestro->setAcceleration(channel,accel);
}
