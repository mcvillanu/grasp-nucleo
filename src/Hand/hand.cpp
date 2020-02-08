#include <Hand/Hand.h>

Hand::Hand(MicroMaestro* maestro) {
    this->maestro = maestro;
}

void Hand::setup() {
    for( int i = 0; i < 5; i ++) {
        this->motors[i].setup();    
    }
}

// bool Hand::next_step() {
//     this->step ++;
//     bool more_steps = false;
//     for( int i = 0; i < 5; i ++) {
//         if(this->grip_table[this->selected_grip][i].size() > this->step) {
//             this->motors[i].move_to(this->grip_table[this->selected_grip][i][this->step]);
//             more_steps = true;
//         }   
//     }
//     return more_steps;
// }

// void Hand::end_step() {
//     for( int i = 0; i < 5; i ++) {
//         int last_elem = this->grip_table[this->selected_grip][i].back();
//         this->motors[i].move_to(last_elem);   
//     }
// }

//user choose grip value between 0-4 (reset is grip 5 done by hand)
void Hand::grip_Choose(int gripVal) {
    for( int i = 0; i < 5; i ++) {
        this->motors[i].moveTo(this->grip_table[gripVal][i]);
    }
}