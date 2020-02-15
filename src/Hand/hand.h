#ifndef HAND_H
#define HAND_H

#include <Communication/MaeComm/MaeComm.h>
#include <Utilities/Constants.h>
#include <vector>
#include <PololuMaestro.h>

using namespace std;

class Hand {
    private:
        int selected_grip;
        int step = 0;
        MicroMaestro* maestro;
        Motor motors[5] = {
            Motor(PINS::PWM::THUMB_PWM,  PINS::FSR::THUMB_FSR,  maestro),
            Motor(PINS::PWM::INDEX_PWM,  PINS::FSR::INDEX_FSR,  maestro),
            Motor(PINS::PWM::MIDDLE_PWM, PINS::FSR::MIDDLE_FSR, maestro),
            Motor(PINS::PWM::RING_PWM,   PINS::FSR::RING_FSR,   maestro),
            Motor(PINS::PWM::PINKY_PWM,  PINS::FSR::PINKY_FSR,  maestro)
        };
        vector<vector<int>> grip_table {
            { {100, 100, 100, 100, 100} },
            { {50,   60,  60, 100, 100} },
            { {100,  20,  20,  30,  40} },
            { {50,   50,  50,  50,  50} },
            { {50,   50,  50,  50,  75} },
            { {0,     0,   0,   0,   0} }
        };

    public:
        Hand();
        Hand(MicroMaestro* maestro);
        void setup();
        bool next_step();
        void end_step();
        void grip_Choose(int gripVal);
};
#endif
