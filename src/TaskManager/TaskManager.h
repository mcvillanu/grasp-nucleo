#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>
#include <Communication/PiComm/PiComm.h>
#include <Utilities/Constants.h>
#include <./Hand/hand.h>
#include <./Wrist/wrist.h>
#include <./StateMachine/StateMachine.h>

class TaskManager
{
    public:
        TaskManager(Wrist* wrist, Hand* hand, StateMachine* sm);
        void updatePendingOrder(int pendingOrder);
        bool executeOrder();
    private:
        int pendingOrder;
        Wrist* wrist;
        Hand* hand;
        StateMachine* stateMachine;
};



#endif