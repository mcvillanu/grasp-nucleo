#define EXECUTE_ID 2

class Execute : public AbstractState {
    private:
        Execute(Execute const &) = delete;
        Execute(Execute const &&) = delete;
        void operator=(Execute const &) = delete;
        void operator=(Execute const &&) = delete;

    public:
        Execute() : AbstractState((unsigned int) EXECUTE_ID) {}
        ~Execute() {}

        std::string * mainLoop();
};

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE METHOD
*/
std::string * Execute::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered execute main loop\n" << std::flush;
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // return wristMessage;
    }
}