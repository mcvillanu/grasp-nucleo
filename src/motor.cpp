#include "motor.h"
#include <Arduino.h>

Motor::Motor(int pin) {
    this->pin = pin;
    this->servo.attach(pin);
    //TODO: Finish this
}

void Motor::move_to(int position) {
    //TODO: Finish this
    this->servo.write(position);
}