#include "motor.h"
#include <Arduino.h>

Motor::Motor(int pin) {
    this->pin = pin;
    // this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::setup() {
    // this->servo.attach(this->pin);
    pinMode(this->pin, OUTPUT);
}

void Motor::move_to(int position) {
    position *= (255/100);
    analogWrite(this->pin, position);
}
