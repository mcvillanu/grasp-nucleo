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
        std::vector<Motor> motors;
        vector<vector<int>> grip_table {
            { {4001, 4001, 4001, 4001, 4001} },
            { {6000,   6400,  6400, 4001, 4001} },
            { {4001,  4800,  4800,  5200,  5600} },
            { {6000,   6000,  6000,  6000,  6000} },
            { {6000,   6000,  6000,  6000,  7000} },
            { {7999,     7999,   7999,   7999,   7999} }
        };

    public:
        Hand(MicroMaestro* maestro);
        void setup();
        bool next_step();
        void end_step();
        void grip_Choose(int gripVal);
};
#endif
