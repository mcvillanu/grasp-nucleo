#define RECEIVING_ID 1

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

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE MESSAGE.
*/
std::string * Receiving::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered receiving main loop\n" << std::flush;
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // srand(time(NULL));

        // int x = rand() % 2;
        // if (x) return safetyMessage;
        // else return standbyMessage;
    }
}