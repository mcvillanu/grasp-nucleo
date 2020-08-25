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



















// #include <stdlib.h>
// #include <stdio.h>
// #include <iostream>
// #include <string.h>
// #include <vector>
// #include <array>
// #include <time.h>
// #include <chrono>
// #include <thread>



// #define SAFETY_ID 0
// #define RECEIVING_ID 1
// #define EXECUTE_ID 2
// #define FAILURE_ID 3
// #define STANDBY_ID 4
// #define WRIST_ID 5



// std::string * const safetyMessage(new std::string("safety"));
// std::string * const receivingMessage(new std::string("receiving"));
// std::string * const executeMessage(new std::string("execute"));
// std::string * const failureMessage(new std::string("failure"));
// std::string * const standbyMessage(new std::string("standby"));
// std::string * const wristMessage(new std::string("wrist"));



// class AbstractState {
//     private:
//         AbstractState() = delete;
//         AbstractState(AbstractState const &) = delete;
//         AbstractState(AbstractState const &&) = delete;
//         void operator=(AbstractState const &) = delete;
//         void operator=(AbstractState const &&) = delete;

//         unsigned int const ID = -1;
//         std::vector<std::pair<std::string,AbstractState *>> * keysAndStates;

//     protected:
//         AbstractState(unsigned int const ID) : ID(ID) {}


//     public:
//         virtual ~AbstractState() {}

//         virtual std::string * mainLoop() = 0;
//         AbstractState * switchState(std::string const & message) {
//             // std::cout << "entering switchState\n" << std::flush;

//             std::vector<std::pair<std::string,AbstractState *>>::iterator itr(this->keysAndStates->begin());
//             for (; itr!=this->keysAndStates->end(); ++itr) if (itr->first == message) return itr->second;
//             // std::cout << "incorrect key pair\n";

//             // std::cout << "exiting switchState\n" << std::flush;
//             // return nullptr;

//             // std::cout << "asdf1\n" << std::flush;
//             // std::cout << (*this->keysAndStates)[0].first << "\n" << std::flush;
//             // std::cout << "asdf2\n" << std::flush;
//             // return (*this->keysAndStates)[0].second;

//             return nullptr;
//         }

//         unsigned int getID() const { return this->ID; }

//         bool setKeysAndStates(std::vector<std::pair<std::string,AbstractState *>> * const keysAndStates) {
//             /*
//             this code is if we want to validate the setup of the state machine connections 
//             coming from this state.
//             No functionality yet for checking non-unique strings or non-unique pointers
//             */

//             // if (alreadySet) return false;
//             // else if (!keysAndStates || (keysAndStates->size() == 0)) return false;
//             // else if (keysAndStates->size() == 1) {

//             // }

//             // this->keysAndStates = keysAndStates;
//             // alreadySet = true;
//             // return true;

//             /*
//                 We are not checking for:
//                     - empty vectors
//                     - vectors of size 1 pointing back to themselves
//                     - vectors that contain non-unique strings
//                     - vectors that contain non-unique pointers
//                 (Due to time complexity reasons)
//                 (Please make sure the vector does not contain any of the above errors)
//             */

//             if (!keysAndStates) return false;
//             this->keysAndStates = keysAndStates;
//             return true;
//         }
// };



// class Safety;
// class Receiving;
// class Execute;
// class Failure;
// class Standby;
// class Wrist;

// class Safety : public AbstractState {
//     private:
//         Safety(Safety const &) = delete;
//         Safety(Safety const &&) = delete;
//         void operator=(Safety const &) = delete;
//         void operator=(Safety const &&) = delete;

//     public:
//         Safety() : AbstractState((unsigned int) SAFETY_ID) {}
//         ~Safety() {}
        
//         std::string * mainLoop();
// };
// class Receiving : public AbstractState {
//     private:
//         Receiving(Receiving const &) = delete;
//         Receiving(Receiving const &&) = delete;
//         void operator=(Receiving const &) = delete;
//         void operator=(Receiving const &&) = delete;

//     public:
//         Receiving() : AbstractState((unsigned int) RECEIVING_ID) {}
//         ~Receiving() {}

//         std::string * mainLoop();
// };
// class Execute : public AbstractState {
//     private:
//         Execute(Execute const &) = delete;
//         Execute(Execute const &&) = delete;
//         void operator=(Execute const &) = delete;
//         void operator=(Execute const &&) = delete;

//     public:
//         Execute() : AbstractState((unsigned int) EXECUTE_ID) {}
//         ~Execute() {}

//         std::string * mainLoop();
// };
// class Failure : public AbstractState {
//     private:
//         Failure(Failure const &) = delete;
//         Failure(Failure const &&) = delete;
//         void operator=(Failure const &) = delete;
//         void operator=(Failure const &&) = delete;
    
//     public:
//         Failure() : AbstractState((unsigned int) FAILURE_ID) {}
//         ~Failure() {}
        
//         std::string * mainLoop();   
// };
// class Standby : public AbstractState {
//     private:
//         Standby(Standby const &) = delete;
//         Standby(Standby const &&) = delete;
//         void operator=(Standby const &) = delete;
//         void operator=(Standby const &&) = delete;

//     public:
//         Standby() : AbstractState((unsigned int) STANDBY_ID) {}
//         ~Standby() {}

//         std::string * mainLoop();
        
// };
// class Wrist : public AbstractState {
//     private:
//         Wrist(Wrist const &) = delete;
//         Wrist(Wrist const &&) = delete;
//         void operator=(Wrist const &) = delete;
//         void operator=(Wrist const &&) = delete;

//     public:
//         Wrist() : AbstractState((unsigned int) WRIST_ID) {}
//         ~Wrist() {}

//         std::string * mainLoop();
// };



// class Manager {
//     private:
//         Manager() = delete;
//         Manager(Manager const &) = delete;
//         Manager(Manager const &&) = delete;
//         void operator=(Manager const &) = delete;
//         void operator=(Manager const &&) = delete;

//         AbstractState * current = nullptr;

//     public:
//         Manager(AbstractState * const current) : current(current) {}
//         ~Manager() {}

//         void run() {
//             while (1) {
//                 std::string * message(nullptr);

//                 switch (this->current->getID()) {
//                     case (SAFETY_ID): {
//                         message = ((Safety *) this->current)->mainLoop();
//                         break;
//                     }
//                     case (RECEIVING_ID): {
//                         message = ((Receiving *) this->current)->mainLoop();
//                         break;
//                     }
//                     case (EXECUTE_ID): {
//                         message = ((Execute *) this->current)->mainLoop();
//                         break;
//                     }
//                     case (FAILURE_ID): {
//                         return;
//                         // message = ((Failure *) this->current)->mainLoop();
//                         // break;
//                     }
//                     case (STANDBY_ID): {
//                         message = ((Standby *) this->current)->mainLoop();
//                         break;
//                     }
//                     case (WRIST_ID): {
//                         message = ((Wrist *) this->current)->mainLoop();
//                         break;
//                     }
//                 }

//                 if (message) {
//                     AbstractState * const nextState(this->current->switchState(*message));
//                     this->current = nextState;
//                 }
//             }
//         }
// };



// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE MESSAGE.
// */
// std::string * Safety::mainLoop() {
//     while (1) {
//         std::cout << "entered safety main loop\n" << std::flush;
//         // ... sleep 5 seconds
//         // we get the JSON message from the Pi, and in the "requestStateChange" key, we have "receiving".
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         return receivingMessage;
//     }
// }

// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE MESSAGE.
// */
// std::string * Receiving::mainLoop() {
//     while (1) {
//         std::cout << "entered receiving main loop\n" << std::flush;
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         srand(time(NULL));

//         int x = rand() % 2;
//         if (x) return safetyMessage;
//         else return standbyMessage;
//     }
// }

// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE METHOD
// */
// std::string * Execute::mainLoop() {
//     while (1) {
//         std::cout << "entered execute main loop\n" << std::flush;
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         return wristMessage;
//     }
// }

// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE METHOD
// */
// std::string * Failure::mainLoop() {
//     while (1) {
//         std::cout << "entered failure main loop\n" << std::flush;
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         return safetyMessage;
//     }
// }

// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE METHOD
// */
// std::string * Standby::mainLoop() {
//     while (1) {
//         std::cout << "entered standby main loop\n" << std::flush;
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         srand(time(NULL));

//         int x = rand() % 3;
//         if (x) return executeMessage;
//         else return receivingMessage;
//     }
// }

// /*
//     THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
//     AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
//     RETURN FROM THIS FUNCTION WITH THE METHOD
// */
// std::string * Wrist::mainLoop() {
//     while (1) {
//         std::cout << "entered wrist main loop\n" << std::flush;
//         std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//         return receivingMessage;
//     }
// }





// int main() {
//     Safety * const safety = new Safety;
//     Receiving * const receiving = new Receiving;
//     Execute * const execute = new Execute;
//     Failure * const failure = new Failure;
//     Standby * const standby = new Standby;
//     Wrist * const wrist = new Wrist;

//     std::pair<std::string,AbstractState *> safety_connect("safety", safety);
//     std::pair<std::string,AbstractState *> receiving_connect("receiving", receiving);
//     std::pair<std::string,AbstractState *> execute_connect("execute", execute);
//     std::pair<std::string,AbstractState *> failure_connect("failure", failure);
//     std::pair<std::string,AbstractState *> standby_connect("standby", standby);
//     std::pair<std::string,AbstractState *> wrist_connect("wrist", wrist);

    

//     std::vector<std::pair<std::string, AbstractState *>> * safety_connections = new std::vector<std::pair<std::string, AbstractState *>>;
//     std::vector<std::pair<std::string, AbstractState *>> * receiving_connections = new std::vector<std::pair<std::string, AbstractState *>>;
//     std::vector<std::pair<std::string, AbstractState *>> * execute_connections = new std::vector<std::pair<std::string, AbstractState *>>;
//     std::vector<std::pair<std::string, AbstractState *>> * failure_connections = new std::vector<std::pair<std::string, AbstractState *>>;
//     std::vector<std::pair<std::string, AbstractState *>> * standby_connections = new std::vector<std::pair<std::string, AbstractState *>>;
//     std::vector<std::pair<std::string, AbstractState *>> * wrist_connections = new std::vector<std::pair<std::string, AbstractState *>>;

//     safety_connections->push_back(receiving_connect);
//     safety_connections->push_back(failure_connect);

//     receiving_connections->push_back(safety_connect);
//     receiving_connections->push_back(standby_connect);
//     receiving_connections->push_back(failure_connect);

//     execute_connections->push_back(wrist_connect);
//     execute_connections->push_back(failure_connect);

//     failure_connections->push_back(safety_connect);

//     standby_connections->push_back(execute_connect);
//     standby_connections->push_back(receiving_connect);
//     standby_connections->push_back(failure_connect);

//     wrist_connections->push_back(receiving_connect);
//     wrist_connections->push_back(failure_connect);



//     safety->setKeysAndStates(safety_connections);
//     receiving->setKeysAndStates(receiving_connections);
//     execute->setKeysAndStates(execute_connections);
//     failure->setKeysAndStates(failure_connections);
//     standby->setKeysAndStates(standby_connections);
//     wrist->setKeysAndStates(wrist_connections);

//     Manager manager(safety);

//     /*
//         This is where we start from:
//     */

//     manager.run();
//     std::cout << "Manager.run() failed.\n" << std::flush;

//     return 0;
// }