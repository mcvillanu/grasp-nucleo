#include <./StateMachine/StateMachine.h>
#include <./Utilities/Constants.h>

#include <Arduino.h>
#include <Servo.h>
#include <Communication/MaeComm/MaeComm.h>
#include <Hand/hand.h>
#include <Wrist/wrist.h>
#include <Communication/PiComm/PiComm.h>
#include <Utilities/Constants.h>
#include <stream.h>
#include <SoftwareSerial.h>
#include <Communication/EMGComm/EMGComm.h>
#include <TaskManager/TaskManager.h>
#include <PololuMaestro.h>
#include <Utilities/JSON/Object/Object.h>
#include <Utilities/JSON/Array/Array.h>
#include <Utilities/JSON/Base/Base.h>
#include <Utilities/JSON/Interpreter/Interpreter.h>
#include <Utilities/Miscellaneous/Miscellaneous.h>
#include <iostream>

int stringToIntGrip(String * grip){
  using namespace GRIPS;
  if (*grip == "mug") { return GRIP_C; }
  else if (*grip =="pinch") { return GRIP_PINCH; }
  else if (*grip =="ball") { return GRIP_BALL; }
  else if (*grip =="hammer") { return GRIP_HAMMER; }
  else if (*grip =="flat") { return GRIP_FLAT; }
  return GRIP_RESET;
}

void readFromPi(){
  message = new String("{\"grip\":\"hammer\", \"c\":false}");
  obj = Interpreter::deserialize<Object>(message);
  grip = stringToIntGrip(obj->getValue<String>("grip"));
  safety = obj->getValue<bool>("c");
}

void setup()
{
  using namespace MAESTRO;
  wrist = new Wrist();
  sm = new StateMachine();
  maestro = new MicroMaestro(maestroSerial);
  hand = new Hand(maestro);
  hand->setup();
  tm = new TaskManager(wrist, hand, sm);
  maestroSerial.begin(9600);
  Pi::setup();
}

void loop()
{
      //stall during safety
  do{
    readFromPi();
  }while(safety);

  tm->updatePendingOrder(grip);

  if(sm->getCurrentState() == STATES::RECEIVING){
    tm->executeOrder();
    delay(2000);
    sm->setState(STATES::IN_GRIP);
  }

  while(sm->getCurrentState() == STATES::IN_GRIP){
    readFromPi();

    if(grip == GRIPS::GRIP_RESET){
      tm->updatePendingOrder(GRIPS::GRIP_RESET);
      tm->executeOrder();
      delay(2000);
      sm->setState(STATES::RECEIVING);
    }
  }
}





// using namespace STATES;
// StateMachine::StateMachine(){
//     this->currentState = (int) SAFETY_ON;
// }

// int StateMachine::getCurrentState(){
//     return this->currentState;
// }

// bool StateMachine::setState(int state){
//     this->currentState = state;
//     return true;
// }