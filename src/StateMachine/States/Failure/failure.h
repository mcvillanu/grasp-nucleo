#ifndef FAILURE_H
#define FAILURE_H



#define FAILURE_ID 3



#include <StateMachine/AbstractState/abstractstate.h>



class Failure : public AbstractState {
    private:
        Failure(Failure const &) = delete;
        Failure(Failure const &&) = delete;
        void operator=(Failure const &) = delete;
        void operator=(Failure const &&) = delete;
    
    public:
        Failure() : AbstractState((unsigned int) FAILURE_ID) {}
        ~Failure() {}
        
        std::string * mainLoop();   
};



#endif
