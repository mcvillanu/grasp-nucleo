#include <TaskManager/TaskManager.h>

TaskManager:: TaskManager(Wrist* wrist, Hand* hand, StateMachine* sm){
    this->wrist = wrist;
    this->hand = hand;
    this->stateMachine = sm;
    this->pendingOrder = 0;
}

bool TaskManager::executeOrder() {
    if(stateMachine->getCurrentState() != STATES::IN_GRIP){
        hand -> grip_Choose(pendingOrder);
        delay(1000);
        Pi::write("inside");
        // switch (this->pendingOrder) {
        //     case GRIPS::GRIP_RESET:
        //         stateMachine->setState(STATES::RECEIVING);
        //         break;

        //     default:
        //         stateMachine->setState(STATES::IN_GRIP);
        //         break;
        // }

        return true;
    } else {
        return false;
    }
}

void TaskManager::updatePendingOrder(int pendingOrder){
    pendingOrder = pendingOrder;
}


