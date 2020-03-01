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
        
        bool executeOrder();
        int stringToIntGrip(String grip);
        void readFromPi();


    public:
        StateMachine();
        int getCurrentState();
        bool setState(int);
        void setup();
        void loop();

};