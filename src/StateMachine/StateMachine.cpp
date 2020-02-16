#include <./StateMachine/StateMachine.h>
#include <./Utilities/Constants.h>

using namespace STATES;
StateMachine::StateMachine(){
    this->currentState = (int) SAFETY_ON;
}

int StateMachine::currentState(){
    return this->currentState;
}

bool StateMachine::setState(int state){
    this->currentState = state;
}