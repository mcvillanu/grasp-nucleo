#define SAFETY_ID 0

class Safety : public AbstractState {
    private:
        Safety(Safety const &) = delete;
        Safety(Safety const &&) = delete;
        void operator=(Safety const &) = delete;
        void operator=(Safety const &&) = delete;

    public:
        Safety() : AbstractState((unsigned int) SAFETY_ID) {}
        ~Safety() {}
        
        std::string * mainLoop();
};

/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE MESSAGE.
*/
std::string * Safety::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        // std::cout << "entered safety main loop\n" << std::flush;
        // ... sleep 5 seconds
        // we get the JSON message from the Pi, and in the "requestStateChange" key, we have "receiving".
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        // return receivingMessage;
    }
}





// class Safety {
//     private:
//     public:
//         Safety();
//         ~Safety();

        
// };