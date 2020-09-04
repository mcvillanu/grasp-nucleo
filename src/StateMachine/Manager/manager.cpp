#include <StateMachine/Manager/manager.h>



void Manager::run() {
    while (1) {
    	std::string * message(nullptr);
		switch (this->current->getID()) {
			case (SAFETY_ID): {
				message = ((Safety *) this->current)->mainLoop();
				break;
			}
			case (RECEIVING_ID): {
				message = ((Receiving *) this->current)->mainLoop();
				break;
			}
			case (EXECUTE_ID): {
				message = ((Execute *) this->current)->mainLoop();
				break;
			}
			case (FAILURE_ID): {
				return;
				// message = ((Failure *) this->current)->mainLoop();
				// break;
			}
			case (STANDBY_ID): {
				message = ((Standby *) this->current)->mainLoop();
				break;
			}
			case (WRIST_ID): {
				message = ((Wrist *) this->current)->mainLoop();
				break;
			}
		}

		if (message) {
			AbstractState * const nextState(this->current->switchState(*message));
			this->current = nextState;
		}
	}
}



// std::string * const safetyMessage    (new std::string("safety"));
// std::string * const receivingMessage (new std::string("receiving"));
// std::string * const executeMessage   (new std::string("execute"));
// std::string * const failureMessage   (new std::string("failure"));
// std::string * const standbyMessage   (new std::string("standby"));
// std::string * const wristMessage     (new std::string("wrist"));









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



































// #include <StateMachine/Manager/manager.h>



// Manager::Manager(Wrist* wrist, Hand* hand): wrist(wrist), hand(hand) {
//   Pi::write("i stuck in constructor help");
//     this->currentState = STATES::SAFETY_ON;
//     this->pendingGrip = GRIPS::GRIP_RESET;
//     hand->grip_Choose(this->pendingGrip);
// }

// int Manager::stringToIntGrip(String * grip){
//   using namespace GRIPS;
//   if (*grip == "mug")
//     return GRIP_C;
//   if (*grip == "pinch")
//     return GRIP_PINCH;
//   if (*grip == "ball")
//     return GRIP_BALL;
//   if (*grip == "hammer")
//     return GRIP_HAMMER;
//   if (*grip == "flat")
//     return GRIP_FLAT;
//   return GRIP_RESET;
// }


// void Manager::readFromPi(){
//     // String * message = new String("{\"grip\":\"hammer\", \"c\":false}");
//     // Object * obj = Interpreter::deserialize<Object>(message);
//     // this->pendingGrip = stringToIntGrip(obj->getValue<String>("grip"));
//     // this->safety = obj->getValue<bool>("c");

//     this->pendingGrip = GRIPS::GRIP_HAMMER;
//     this->safetyBool = false;
// }

// void Manager::safety()
// {
//   Pi::write("\n received safety");
//   hand->grip_Choose(this->pendingGrip);
//   this->currentState = STATES::SAFETY_ON;
// }

// void Manager::executeGrip()
// {
//   hand->grip_Choose(this->pendingGrip);
//   delay(2000);
//   this->currentState = STATES::IN_GRIP;
// }

// void Manager::reset()
// {
//   hand->grip_Choose(this->pendingGrip);
//   delay(2000);
//   this->currentState = STATES::RECEIVING;
// }

// void Manager::poll()
// {
//   //BMS
//   //EMG???
//   //sets safety based off of BMS?
// }

// void Manager::run(){

//   while(true)
//   {
//     //debug
//     Pi::write("\n current state: " + this->currentState);
//     Pi::write("\n safety: " + (this->currentState==STATES::SAFETY_ON));
//     //debug
//     this->readFromPi();
//     poll();
//     if(this->currentState == STATES::SAFETY_ON && this->safetyBool == false)
//     {
//       this->currentState = STATES::RECEIVING;
//     }
//     if (this->safetyBool)
//     {
//       safety();
//     }
//     else
//     {
//       if (this->currentState == STATES::RECEIVING)
//       {
//         executeGrip();
//       }
//       else if (this->currentState == STATES::IN_GRIP)
//       {
//         if(this->pendingGrip == GRIPS::GRIP_RESET) 
//         {
//           reset();
//         }
//         else
//         {
//           Pi::write("\n cannot execute another grip until grip has bee reset");
//         }
//       }
//       else
//       {
//         Pi::write("\n error in manager run(): unexpected state is: " + this->currentState);
//       }
//     }

    
//   }
//   // do {
//   //   this->readFromPi();
//   //   Pi::write("\n I do be stuck");
//   // } while (this->safety);

//   // Pi::write("\n safety: " + this->safety);

//   // this->currentState = STATES::RECEIVING;

//   // Pi::write("\n current state: " + this->currentState);

//   // while(true){
//   //   if(this->currentState == STATES::RECEIVING){
//   //     hand->grip_Choose(this->pendingGrip);
//   //     delay(2000);
//   //     this->currentState = STATES::IN_GRIP;
//   //   }

//   //   while(this->currentState == STATES::IN_GRIP){
//   //     readFromPi();

//   //     if(this->pendingGrip == GRIPS::GRIP_RESET){
//   //       hand->grip_Choose(this->pendingGrip);
//   //       delay(2000);
//   //       this->currentState = STATES::RECEIVING;
//   //     }
//   //   }
//   // }
// }