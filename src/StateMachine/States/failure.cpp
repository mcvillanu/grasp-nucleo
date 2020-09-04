#define FAILURE_ID 3

class Failure : public AbstractState {
    private:
        Failure(Failure const &) = delete;
        Failure(Failure const &&) = delete;
        void operator=(Failure const &) = delete;
        void operator=(Failure const &&) = delete;
    
    public:
        Failure() : AbstractState((unsigned int) FAILURE_ID) {}
        ~Failure() {}
        
        std::string * mainLoop();   
};

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE METHOD
*/
std::string * Failure::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered failure main loop\n" << std::flush;
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // return safetyMessage;
    }
}