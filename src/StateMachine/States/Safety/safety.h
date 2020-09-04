#ifndef SAFETY_H
#define SAFETY_H



#define SAFETY_ID 0



#include <StateMachine/AbstractState/abstractstate.h>



class Safety : public AbstractState {
    private:
        Safety(Safety const &) = delete;
        Safety(Safety const &&) = delete;
        void operator=(Safety const &) = delete;
        void operator=(Safety const &&) = delete;

    public:
        Safety() : AbstractState((unsigned int) SAFETY_ID) {}
        ~Safety() {}
        
        std::string * mainLoop();
};



#endif
