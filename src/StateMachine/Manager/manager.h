#ifndef MANAGER_H
#define MANAGER_H



#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>



#include <StateMachine/AbstractState/abstractstate.h>



#define SAFETY_ID    0
#define RECEIVING_ID 1
#define EXECUTE_ID   2
#define FAILURE_ID   3
#define STANDBY_ID   4
#define WRIST_ID     5



class Manager {
    private:
        Manager() = delete;
        Manager(Manager const &) = delete;
        Manager(Manager const &&) = delete;
        void operator=(Manager const &) = delete;
        void operator=(Manager const &&) = delete;

        AbstractState * current = nullptr;

    public:
        Manager(AbstractState * const current) : current(current) {}
        ~Manager() {}

        void run();
};



// #include <Wrist/wrist.h>
// #include <Hand/hand.h>
// // #include <Utilities/JSON/Interpreter/Interpreter.h>
// #include <Arduino.h>



// class Manager {
//     public:
//         Manager(Wrist* wrist, Hand* hand);
//         void run();
//         void readFromPi();

//     private:
//         int stringToIntGrip(String * grip);
//         int currentState;
//         int pendingGrip;
//         bool safetyBool;
//         Wrist * wrist;
//         Hand * hand;

//         //states:
//         void safety();
//         void executeGrip();
//         void reset();
//         void poll();
// };

#endif