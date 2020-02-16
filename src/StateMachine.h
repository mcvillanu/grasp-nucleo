#include <./Utilities/Constants.h>

class StateMachine {
    private:
        bool open;
        bool safety;
        bool recieving;
        bool gripStandby;
        bool executingGrip;
        bool wristMotion;
        bool blindDistSensing;
    public:
        int currentState();
        bool setState(int);
};