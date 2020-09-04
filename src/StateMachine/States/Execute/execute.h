#ifndef EXECUTE_H
#define EXECUTE_H



#define EXECUTE_ID 2



#include <StateMachine/AbstractState/abstractstate.h>



class Execute : public AbstractState {
    private:
        Execute(Execute const &) = delete;
        Execute(Execute const &&) = delete;
        void operator=(Execute const &) = delete;
        void operator=(Execute const &&) = delete;

    public:
        Execute() : AbstractState((unsigned int) EXECUTE_ID) {}
        ~Execute() {}

        std::string * mainLoop();
};



#endif
