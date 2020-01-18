#ifndef HAND_H
#define HAND_H
#include <motor.h>
#include <constants.h>
#include <vector>
using namespace std;


class Hand {
    public:
        /**
        * Default constructor for the hand.
        **/
        Hand();
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


        Motor motors[5] = {
            Motor(PINS::THUMB_PWM,PINS::THUMB_FSR),
            Motor(PINS::INDEX_PWM,PINS::INDEX_FSR),
            Motor(PINS::MIDDLE_PWM,PINS::MIDDLE_FSR),
            Motor(PINS::RING_PWM,PINS::RING_FSR),
            Motor(PINS::PINKY_PWM,PINS::PINKY_FSR),
        };

        vector<vector<int>> grip_table {
            //Grip 0 (Hammer)
            {
                //Finger 1-5 
                {100, 100, 100, 100, 100},
            },
            //Grip 1 (Pinch)
            {
                //Finger 1-5 
                {50, 60, 60, 100, 100},
            },
            //Grip 2 (Card)
            {
             //Finger 1-5 
                {100, 20, 20, 30, 40},
            },
            //Grip 3 (Ball)
            {
             //Finger 1-5 
                {50, 50, 50, 50, 50},
            },
            //Grip 4 (Cup)
            {
             //Finger 1-5 
                {50, 50, 50, 50, 75},
            },
            //Grip 5 (Reset)
            {
             //Finger 1-5 
                {0, 0, 0, 0, 0},
            },
        };

};
#endif
