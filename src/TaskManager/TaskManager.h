#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>
#include <Communication/PiComm/PiComm.h>
#include <Utilities/Constants.h>
#include <./Hand/hand.h>
#include <./Wrist/wrist.h>

class TaskManager
{
    public:
        TaskManager(Wrist* wrist, Hand* hand);
        void update(int order);
        void executeOrder();
    private:
        int pendingOrder;
        Wrist* wrist;
        Hand* hand;
};



#endif