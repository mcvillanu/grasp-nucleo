#include "motor.h"
#include <Arduino.h>
#include <communication.h>
#include <PololuMaestro.h>

Motor::Motor(int pin, int fsrpin, MicroMaestro* maestro) {
    this->pin = pin;
    this->fsrpin = fsrpin;
    this->maestro = maestro;
    // this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::setup() {
    // this->servo.attach(this->pin);
    pinMode(this->pin, OUTPUT);
}

void Motor::move_to(uint16_t position) {
    if (!fsr.safetyBrake() || position<=currPos){
        currPos = position;
        // If brake is on, finger can only release
        //analogWrite(this->pin, position);
        maestro->setTarget(this->pin,position);
    } else {
        // TODO: communicate that the brake is on
    }
    
}

void Motor::setSpeed(uint16_t speed){
    maestro->setSpeed(pin,speed);
}

void Motor::setAcceleration(uint16_t accel){
    maestro->setAcceleration(pin,accel);
}
