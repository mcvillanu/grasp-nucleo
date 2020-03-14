#ifndef MANAGER_H
#define MANAGER_H
#include <Wrist/wrist.h>
#include <Hand/hand.h>
// #include <Utilities/JSON/Interpreter/Interpreter.h>
#include <Arduino.h>

class Manager
{
    public:
        Manager(Wrist* wrist, Hand* hand);
        void run();
        void readFromPi();
    private:
        int stringToIntGrip(String * grip);
        int currentState;
        int pendingGrip;
        bool safety;
        Wrist * wrist;
        Hand * hand;

        //states:
        void safety();
        void Manager::executeGrip();
        void Manager::reset();
        void Manager::poll();
};
#endif