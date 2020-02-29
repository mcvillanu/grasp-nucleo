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
        vector<Motor> motors;
        vector<vector<int>> grip_table {
            // hammer // 4000-8000 and 4000 is closed
            { {4100, 4100, 4100, 4100, 4100} },
            // pinch
            { {4100,   4100,  4100, 6400, 6400} },
            // card/flat
            { {4100,  4800,  4800,  5200,  5600} },
            //ball
            { {6000,   6000,  6000,  6000,  6000} },
            //cup
            { {6200,   6200,  6200,  6200,  6200} },
            // reset  
            { {7900,   7900, 7900,  7900, 7900} }
        };

    public:
        Hand();
        Hand(MicroMaestro* maestro);
        void setup();
        MicroMaestro* maestro;
       
        void grip_Choose(int gripVal);
};
#endif
