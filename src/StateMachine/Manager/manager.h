#ifndef MANAGER_H
#define MANAGER_H



#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>



#include <StateMachine/AbstractState/abstractstate.h>
#include <StateMachine/States/Execute/execute.h>
#include <StateMachine/States/Failure/failure.h>
#include <StateMachine/States/Receiving/receiving.h>
#include <StateMachine/States/Safety/safety.h>
#include <StateMachine/States/Standby/standby.h>
#include <StateMachine/States/Wrist/wrist.h>



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



#endif
