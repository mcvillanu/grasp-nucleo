#ifndef STANDBY_H
#define STANDBY_H



#define STANDBY_ID 4



#include <StateMachine/AbstractState/abstractstate.h>



class Standby : public AbstractState {
    private:
        Standby(Standby const &) = delete;
        Standby(Standby const &&) = delete;
        void operator=(Standby const &) = delete;
        void operator=(Standby const &&) = delete;

    public:
        Standby() : AbstractState((unsigned int) STANDBY_ID) {}
        ~Standby() {}

        std::string * mainLoop();
};



#endif
