#include "motor.h"
#include <Arduino.h>
#include <communication.h>

Motor::Motor(int pin, int fsrpin) {
    this->pin = pin;
    this->fsrpin = fsrpin;
    // this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::setup() {
    // this->servo.attach(this->pin);
    pinMode(this->pin, OUTPUT);
}

void Motor::move_to(int position) {
    if (!fsr.safetyBrake() || position<=currPos){
        currPos = position;
        // If brake is on, finger can only release
        position *= (255/100);
        analogWrite(this->pin, position);
    } else {
        // TODO: communicate that the brake is on
    }
}
