#include "hand.h"
#include "motor.h"
#include <PololuMaestro.h>
#include <Arduino.h>


Hand::Hand(MicroMaestro* maestro) {
    this->maestro = maestro;
    // this->motors = new Motor(0,  0,  maestro);
    this->motors.push_back(Motor(1,  0,  maestro));
    this->motors.push_back(Motor(2, 0, maestro));
    this->motors.push_back(Motor(3,  0,   maestro));
    this->motors.push_back(Motor(4,  0,  maestro));
}

void Hand::setup() {
    for( int i = 0; i < 5; i ++) {
        // this->motors[i].setup();    
    }
}
//user choose grip value between 0-4 (reset is grip 5 done by hand)
void Hand::grip_Choose(int gripVal) {
    for( int i = 0; i < 5; i ++) {
        this->motors[i].move_to(this->grip_table[gripVal][i]);
    }
        Serial.println("hwi");
        // this->motors->move_to(7999);

}
