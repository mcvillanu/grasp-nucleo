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
        vector<Motor> motors;
        vector<vector<int>> grip_table {
            // hammer
            { {4001, 4001, 4001, 4001, 4001} },
            // pinch
            { {6000,   6400,  6400, 4001, 4001} },
            // card/flat
            { {4001,  4800,  4800,  5200,  5600} },
            //ball
            { {6000,   6000,  6000,  6000,  6000} },
            //cup
            { {6000,   6000,  6000,  6000,  7000} },
            // reset  
            { {7999,     7999,   7999,   7999,   7999} }
        };

    public:
        Hand();
        Hand(MicroMaestro* maestro);
        void setup();
        void grip_Choose(int gripVal);
        // FSR or destination reached flag 
        int motor_flag[5] = { 0 , 0 , 0 , 0 , 0 };
       
};
#endif
