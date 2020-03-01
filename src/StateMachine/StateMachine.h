#include <./Utilities/Constants.h>

class StateMachine {
    private:
        int currentState;
    public:
        StateMachine();
        int getCurrentState();
        bool setState(int);
};