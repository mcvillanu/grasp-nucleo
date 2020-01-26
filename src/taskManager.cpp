#include "taskManager.h"
#include <Arduino.h>
#include <communication.h>

 TaskManager::TaskManager() {}

void TaskManager::executeOrder(int order)
{
    switch (order) {
        case MSG::GRIP_HAMMER : gripHammer(); break;
        case MSG::GRIP_PINCH  : gripPinch();  break;
        case MSG::GRIP_BALL   : gripBall();   break;
        case MSG::GRIP_FLAT   : gripFlat();   break;
        case MSG::GRIP_C      : gripC();      break;
    }
    return;
}

void TaskManager::gripHammer() {
    return;
}

void TaskManager::gripPinch() {
    return;
}

void TaskManager::gripBall() {
    return;
}

void TaskManager::gripFlat() {
    return;
}

void TaskManager::gripC() {
    return;
}


