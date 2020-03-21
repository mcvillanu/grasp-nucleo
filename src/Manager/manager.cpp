#include <Manager/manager.h>

Manager::Manager(Wrist* wrist, Hand* hand): wrist(wrist), hand(hand) {
  Pi::write("i stuck in constructor help");
    this->currentState = STATES::SAFETY_ON;
    this->pendingGrip = GRIPS::GRIP_RESET;
    hand->grip_Choose(this->pendingGrip);
}

int Manager::stringToIntGrip(String * grip){
  using namespace GRIPS;
  if (*grip == "mug")
    return GRIP_C;
  if (*grip == "pinch")
    return GRIP_PINCH;
  if (*grip == "ball")
    return GRIP_BALL;
  if (*grip == "hammer")
    return GRIP_HAMMER;
  if (*grip == "flat")
    return GRIP_FLAT;
  return GRIP_RESET;
}


void Manager::readFromPi(){
    // String * message = new String("{\"grip\":\"hammer\", \"c\":false}");
    // Object * obj = Interpreter::deserialize<Object>(message);
    // this->pendingGrip = stringToIntGrip(obj->getValue<String>("grip"));
    // this->safety = obj->getValue<bool>("c");

    this->pendingGrip = GRIPS::GRIP_HAMMER;
    this->safetyBool = false;
}

void Manager::safety()
{
  Pi::write("\n received safety");
  hand->grip_Choose(this->pendingGrip);
  this->currentState = STATES::SAFETY_ON;
}

void Manager::executeGrip()
{
  hand->grip_Choose(this->pendingGrip);
  delay(2000);
  this->currentState = STATES::IN_GRIP;
}

void Manager::reset()
{
  hand->grip_Choose(this->pendingGrip);
  delay(2000);
  this->currentState = STATES::RECEIVING;
}

void Manager::poll()
{
  //BMS
  //EMG???
  //sets safety based off of BMS?
}

void Manager::run(){

  while(true)
  {
    //debug
    Pi::write("\n current state: " + this->currentState);
    Pi::write("\n safety: " + (this->currentState==STATES::SAFETY_ON));
    //debug
    this->readFromPi();
    poll();
    if(this->currentState == STATES::SAFETY_ON && this->safetyBool == false)
    {
      this->currentState = STATES::RECEIVING;
    }
    if (this->safetyBool)
    {
      safety();
    }
    else
    {
      if (this->currentState == STATES::RECEIVING)
      {
        executeGrip();
      }
      else if (this->currentState == STATES::IN_GRIP)
      {
        if(this->pendingGrip == GRIPS::GRIP_RESET) 
        {
          reset();
        }
        else
        {
          Pi::write("\n cannot execute another grip until grip has bee reset");
        }
      }
      else
      {
        Pi::write("\n error in manager run(): unexpected state is: " + this->currentState);
      }
    }

    
  }
  // do {
  //   this->readFromPi();
  //   Pi::write("\n I do be stuck");
  // } while (this->safety);

  // Pi::write("\n safety: " + this->safety);

  // this->currentState = STATES::RECEIVING;

  // Pi::write("\n current state: " + this->currentState);

  // while(true){
  //   if(this->currentState == STATES::RECEIVING){
  //     hand->grip_Choose(this->pendingGrip);
  //     delay(2000);
  //     this->currentState = STATES::IN_GRIP;
  //   }

  //   while(this->currentState == STATES::IN_GRIP){
  //     readFromPi();

  //     if(this->pendingGrip == GRIPS::GRIP_RESET){
  //       hand->grip_Choose(this->pendingGrip);
  //       delay(2000);
  //       this->currentState = STATES::RECEIVING;
  //     }
  //   }
  // }
}