#ifndef HAND_H
#define HAND_H
#include <motor.h>
// #include <constants.h>
#include <vector>
#include <PololuMaestro.h>
using namespace std;

class Hand {
    public:
        /**
        * Default constructor for the hand.
        **/
        Hand(MicroMaestro* maestro);
        /**
         * sets up motors and hand
         * Uses the base ordering schema defined in communication.
         **/
        void setup();
        /**
         * For EMG Motion. Moves to the next step of the defined grip pattern.
         * Returns True if there are more steps to be done, false otherwise.
         **/
        bool next_step();
        /**
         * For Non-EMG Motion. Queues the final step of the grip to the motors.
         **/
        void end_step();
        /**
         *  User chooses 1 of 5 grips, that value determines grip positions for each
         **/
        void grip_Choose(int gripVal);
    private:
        int selected_grip;
        int step = 0;
        MicroMaestro* maestro;
        std::vector<Motor> motors;
        // Motor * motors;
        vector<vector<int>> grip_table {
            //Grip 0 (Hammer)
            {
                //Finger 1-5 
                {4001, 4001, 4001, 4001, 4001},
            },
            //Grip 1 (Pinch)
            {
                //Finger 1-5 
                {7999, 5000, 5000, 4001, 4001},
            },
            //Grip 2 (Card)
            {
             //Finger 1-5 
                {4001, 4001, 4001, 4001, 4001},
            },
            //Grip 3 (Ball)
            {
             //Finger 1-5 
               {4001, 4001, 4001, 4001, 4001},
            },
            //Grip 4 (Cup)
            {
             //Finger 1-5 
               {4001, 4001, 4001, 4001, 4001},
            },
            //Grip 5 (Reset)
            {
             //Finger 1-5 
               {4001, 4001, 4001, 4001, 4001},
            },
        };

};
#endif
