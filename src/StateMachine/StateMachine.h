#include <./Utilities/Constants.h>

class StateMachine {
    private:
        int currentState;
    public:
        StateMachine();
        int currentState();
        bool setState(int);
};