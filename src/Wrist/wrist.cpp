/*
 * Using accelerated motion ("linear speed") in nonblocking mode
 *
 * Copyright (C)2015-2017 Laurentiu Badea
 *
 * This file may be redistributed under the terms of the MIT license.
 * A copy of this license has been included with this distribution in the file LICENSE.
 */
/*
 * Choose one of the sections below that match your board
 */

//#include <Communication/MaeComm/MaeComm.h>
#include <Arduino.h>
#include <Wrist/wrist.h>

Wrist::Wrist(){}

Wrist::Wrist(int microsteps) {
    this->microsteps = microsteps;
}

void Wrist::setup() {
    // this->servo.attach(this->pin);
    stepper.begin(VARS::WRIST_RPM, this->microsteps);
    // if using enable/disable on ENABLE pin (active LOW) instead of SLEEP uncomment next line
    // stepper.setEnableActiveState(LOW);
    stepper.enable();
    /*
     * Set LINEAR_SPEED (accelerated) profile.
     */ 
    //stepper.setSpeedProfile(stepper.CONSTANT_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
    /*
     * Using non-blocking mode to print out the step intervals.
     * We could have just as easily replace everything below this line with 
     * stepper.rotate(360);
     */
}

void Wrist::rotate_by(int angle) {
    stepper.rotate(angle);
}

unsigned Wrist::poll() {
     unsigned wait_time_micros = stepper.nextAction();
     return wait_time_micros;
}