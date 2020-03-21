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
    Pi::write("\nin setup");
    for( int i = 0; i < 5; i ++) {
        Pi::write("\n help  " + i);
        this->motors[i].setup();    
    }
}

/*
for 0 to 5 each motor
    each finger 4000-8000 (8000 is open) each finger move (-100) each cycle and 
    check A. if FSR reached or B. reached the destination
    if either, set finger flag and dont move anymore

    8000-> 4000
*/


//user choose grip value between 0-4 (reset is grip 5 done by hand)
void Hand::grip_Choose(int gripVal) {
    // Manual reset or ?
    for( int i = 0; i < 5; i ++) {
        this->motors[i].moveTo(7999);
    }

    int finger_fsr[5]; //placeholder, create an array for each finger FSR elsewhere

    // move 200 steps each cycle
    for (int j = 0; j > 4000; j = j - 200) {
        for( int i = 0; i < 5; i ++) {
            // check if A. j has reach the required destination, and B. that finger FSR hasn't been triggered and
            // C. motor flag hasn't been triggered
            if (j > this->grip_table[gripVal][i] & finger_fsr[i] == 0 & this->motor_flag[i] == 0) {
                this->motors[i].moveTo(j);
            }
            else {
                this->motor_flag[i] = 1;
            }
        }
        while(maestro->getMovingState()); // returns 1 if servo is running
                                          // check to see if all servos have stopped moving, unsure if needed
    }

    // reset flags
    for (int k; k < 5; k++) {
        this->motor_flag[k] = 0;
    }

    Pi::write("\nfinished grip_choose");
}