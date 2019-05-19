#include "hand.h"
#include <constants.h>

Hand::Hand() {
    this->motors.push_back(Motor(PINS::THUMB_PWM));
    this->motors.push_back(Motor(PINS::INDEX_PWM));
    this->motors.push_back(Motor(PINS::MIDDLE_PWM));
    this->motors.push_back(Motor(PINS::RING_PWM));
    this->motors.push_back(Motor(PINS::PINKY_PWM));

}

void Hand::start_grip(int grip_id) {
    this->step = 0;
    this->selected_grip = grip_id;
}

bool Hand::next_step() {
    this->step ++;
    bool more_steps = false;
    for( int i = 0; i < 5; i ++) {
        if(this->grip_table[this->selected_grip][i].size() > this->step) {
            this->motors[i].move_to(this->grip_table[this->selected_grip][i][this->step]);
            more_steps = true;
        }   
    }
    return more_steps;
}

void Hand::end_step() {
    for( int i = 0; i < 5; i ++) {
        int last_elem = this->grip_table[this->selected_grip][i].back();
        this->motors[i].move_to(last_elem);   
    }
}
