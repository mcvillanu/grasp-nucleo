#include <TaskManager/TaskManager.h>

TaskManager:: TaskManager(Wrist wrist, Hand hand){
    this->wrist = wrist;
    this->hand = hand;
}

void TaskManager::executeOrder(int order) {
    switch (order) {
        case GRIPS::GRIP_HAMMER : gripHammer(); break;
        case GRIPS::GRIP_PINCH  : gripPinch();  break;
        case GRIPS::GRIP_BALL   : gripBall();   break;
        case GRIPS::GRIP_FLAT   : gripFlat();   break;
        case GRIPS::GRIP_C      : gripC();      break;
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


