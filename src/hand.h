#ifndef HAND_H
#define HAND_H
#include <motor.h>
#include <map>
#include <vector>
using namespace std;


class Hand {
    public:
        /**
        * Default constructor for the hand.
        **/
        Hand();
        /**
         * Begins a new grip. 
         * Uses the base ordering schema defined in communication.
         **/
        void start_grip(int grip_id);
        /**
         * For EMG Motion. Moves to the next step of the defined grip pattern. 
         * Returns True if there are more steps to be done, false otherwise.
         **/
        bool next_step();
        /**
         * For Non-EMG Motion. Queues the final step of the grip to the motors. 
         **/
        void end_step();
    private:

        int selected_grip;
        int step = 0;

        vector<Motor> motors;
        vector<vector<vector<int>>> grip_table  {
            //Grip 0 (Hammer)
            {
                //Finger 0 (Thumb)
                {0, 1, 2, 3, 4},
                //Finger 1
                {24, 23, 22, 21, 20},
                //Finger 2
                {30, 31, 32, 33, 34},
                //Finger 3
                {54, 53, 52, 51, 50},
                //Finger 3
                {24, 23, 22, 21, 20},
            },
            //Grip 1 (Pinch)
            {
                //Finger 0 (Thumb)
                {0, 1, 2, 3, 4},
                //Finger 1
                {24, 23, 22, 21, 20},
                //Finger 2
                {30, 31, 32, 33, 34},
                //Finger 3
                {54, 53, 52, 51, 50},
                //Finger 3
                {24, 23, 22, 21, 20},
            }
            //...
        };
    
};
#endif