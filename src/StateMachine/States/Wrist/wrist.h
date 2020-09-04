#ifndef WRIST_H
#define WRIST_H



#define WRIST_ID 5



#include <StateMachine/AbstractState/abstractstate.h>



class Wrist : public AbstractState {
    private:
        Wrist(Wrist const &) = delete;
        Wrist(Wrist const &&) = delete;
        void operator=(Wrist const &) = delete;
        void operator=(Wrist const &&) = delete;

    public:
        Wrist() : AbstractState((unsigned int) WRIST_ID) {}
        ~Wrist() {}

        std::string * mainLoop();
};



#endif
