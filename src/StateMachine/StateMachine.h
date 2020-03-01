#include <./Utilities/Constants.h>

class StateMachine {
    private:
        int currentState;
        int grip;
        bool * safety;
        bool emgTrigger = false;
        Wrist *wrist;
        TaskManager *tm;
        SoftwareSerial maestroSerial(COMMUNICATION::MAECOMM::RX, COMMUNICATION::MAECOMM::TX);
        MicroMaestro * maestro;
        Hand * hand;
        String * message;
        Object * obj;


        int stringToIntGrip(String grip);
        void readFromPi();


    public:
        StateMachine();
        int getCurrentState();
        bool setState(int);
};