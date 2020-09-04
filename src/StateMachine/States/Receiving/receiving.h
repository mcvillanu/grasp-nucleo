#ifndef RECEIVING_H
#define RECEIVING_H



#define RECEIVING_ID 1



#include <StateMachine/AbstractState/abstractstate.h>



class Receiving : public AbstractState {
    private:
        Receiving(Receiving const &) = delete;
        Receiving(Receiving const &&) = delete;
        void operator=(Receiving const &) = delete;
        void operator=(Receiving const &&) = delete;

    public:
        Receiving() : AbstractState((unsigned int) RECEIVING_ID) {}
        ~Receiving() {}

        std::string * mainLoop();
};



#endif
