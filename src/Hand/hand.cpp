#include <Hand/Hand.h>

Hand::Hand(){}

Hand::Hand(MicroMaestro* maestro) {
    this->maestro = maestro;
    this->motors.push_back(Motor(PINS::CHAN::THUMB_MOTOR,  PINS::FSR::THUMB_FSR,  maestro));
    this->motors.push_back(Motor(PINS::CHAN::INDEX_MOTOR,  PINS::FSR::INDEX_FSR,  maestro));
    this->motors.push_back(Motor(PINS::CHAN::MIDDLE_MOTOR, PINS::FSR::MIDDLE_FSR, maestro));
    this->motors.push_back(Motor(PINS::CHAN::RING_MOTOR,   PINS::FSR::RING_FSR,   maestro));
    this->motors.push_back(Motor(PINS::CHAN::PINKY_MOTOR,  PINS::FSR::PINKY_FSR,  maestro));
}

void Hand::setup() {
    for( int i = 0; i < 5; i ++) {
        this->motors[i].setup();    
    }
}

//user choose grip value between 0-4 (reset is grip 5 done by hand)
void Hand::grip_Choose(int gripVal) {
    for( int i = 0; i < 5; i ++) {
        this->motors[i].moveTo(this->grip_table[gripVal][i]);
     
    Pi::write(String(this->grip_table[gripVal][i]));
    }
}