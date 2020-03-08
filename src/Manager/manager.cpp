#include <Manager/manager.h>

int Manager::stringToIntGrip(String * grip){
  using namespace GRIPS;
  if (*grip == "mug") { return GRIP_C; }
  else if (*grip == "pinch") { return GRIP_PINCH; }
  else if (*grip == "ball") { return GRIP_BALL; }
  else if (*grip == "hammer") { return GRIP_HAMMER; }
  else if (*grip == "flat") { return GRIP_FLAT; }
  return GRIP_RESET;
}

Manager::Manager(Wrist* wrist, Hand* hand): wrist(wrist), hand(hand) {
  Pi::write("i stuck in constructor help");
    this->currentState = STATES::SAFETY_ON;
    this->pendingGrip = GRIPS::GRIP_RESET;
    hand->grip_Choose(this->pendingGrip);
}

void Manager::run(){
  do {
    this->readFromPi();
    Pi::write("\n I do be stuck");
  } while (this->safety);

  Pi::write("\n safety: " + this->safety);

  this->currentState = STATES::RECEIVING;

  Pi::write("\n current state: " + this->currentState);

  while(true){
    if(this->currentState == STATES::RECEIVING){
      hand->grip_Choose(this->pendingGrip);
      delay(2000);
      this->currentState = STATES::IN_GRIP;
    }

    while(this->currentState == STATES::IN_GRIP){
      readFromPi();

      if(this->pendingGrip == GRIPS::GRIP_RESET){
        hand->grip_Choose(this->pendingGrip);
        delay(2000);
        this->currentState = STATES::RECEIVING;
      }
    }
  }
}

void Manager::readFromPi(){
    // String * message = new String("{\"grip\":\"hammer\", \"c\":false}");
    // Object * obj = Interpreter::deserialize<Object>(message);
    // this->pendingGrip = stringToIntGrip(obj->getValue<String>("grip"));
    // this->safety = obj->getValue<bool>("c");

    this->pendingGrip = GRIPS::GRIP_HAMMER;
    this->safety = false;
}