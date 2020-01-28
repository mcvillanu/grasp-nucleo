#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>
#include <communication.h>
#include <constants.h>


class TaskManager
{
    public:
        TaskManager();
        void executeOrder(int order);
    private:
        int order;
        int init;

        void gripHammer();
        void gripPinch();
        void gripBall();
        void gripFlat();                                                          
        void gripC();
};



#endif