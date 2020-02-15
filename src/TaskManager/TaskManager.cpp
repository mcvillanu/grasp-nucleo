#include <TaskManager/TaskManager.h>

TaskManager:: TaskManager(Wrist* wrist, Hand* hand){
    this->wrist = wrist;
    this->hand = hand;
    this->pendingOrder = 0;
}

void TaskManager::executeOrder() {
    hand -> grip_Choose(pendingOrder);
}

void TaskManager::update(int order){
    pendingOrder = order;
}


