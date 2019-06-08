#include "motor.h"
#include <Arduino.h>

Motor::Motor(int pin) {
    this->pin = pin;
    // this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::setup() {
    // this->servo.attach(this->pin);
}

void Motor::move_to(int position) {
    //This needs to be adjusted for STM
    position /= 1.7;
    position += 70;
    analogWrite(this->pin, position);
}