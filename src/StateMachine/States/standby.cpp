#define STANDBY_ID 4

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

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE METHOD
*/
std::string * Standby::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered standby main loop\n" << std::flush;
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // srand(time(NULL));

        // int x = rand() % 3;
        // if (x) return executeMessage;
        // else return receivingMessage;
    }
}