#include <hapticFeedback.h>
#include <Arduino.h>

Haptic::Haptic(int pin) {
    this->pin = pin;
}

void Haptic::setup() {
    pinMode(this->pin, OUTPUT);
}

void Haptic::haptic(int power, int time) {
    //turning the motor on to specified power for 1000ms
    analogWrite(pin, power);
    delay(1000);
    Serial.println("specified power");

    //turning the motor off for specified time
    analogWrite(pin, 255);
    delay(time);
    Serial.println("off");
}