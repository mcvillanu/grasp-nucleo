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
        TaskManager(Wrist wrist, Hand hand);
        bool update();
        void executeOrder(int order);
    private:
        int order;
        int init;
        Wrist wrist;
        Hand hand;

        void gripHammer();
        void gripPinch();
        void gripBall();
        void gripFlat();
        void gripC();
};



#endif