#define WRIST_ID 5

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

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE METHOD
*/
std::string * Wrist::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered wrist main loop\n" << std::flush;
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // return receivingMessage;

    }
}
