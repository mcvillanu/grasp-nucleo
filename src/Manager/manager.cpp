#include <Manager/manager.h>

Manager::Manager(Wrist* wrist, Hand* hand): wrist(wrist), hand(hand) {
  Pi::write("i stuck in constructor help");
    this->currentState = STATES::SAFETY_ON;
    this->pendingGrip = GRIPS::GRIP_RESET;
    hand->grip_Choose(this->pendingGrip);
}

int Manager::stringToIntGrip(String * grip){
  using namespace GRIPS;
  switch (*grip)
  {
  case "mug":     return GRIP_C;
  case "pinch":   return GRIP_PINCH;
  case "ball":    return GRIP_BALL;
  case "hammer":  return GRIP_HAMMER;
  case "flat":    return GRIP_FLAT;
  default:        return GRIP_RESET;
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

void safety()
{
  Pi::write("\n received safety");
  hand->grip_Choose(this->pending);
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

void Manager::run(){

  while(true)
  {
    //debug
    Pi::write("\n current state: " + this->currentState);
    Pi::write("\n safety: " + (this->currentState==SAFETY_ON));
    //debug
    this->readFromPi();
    if(this->currentState == STATES::SAFETY_ON && this->safety == false)
    {
      this->currentState = STATES::RECEIVING;
    }
    if (this->safety)
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