#include <StateMachine/States/Receiving/receiving.h>



/*
    THIS IS WHERE THE MAINLOOP FOR THE SAFETY STATE GOES...
    AS SOON AS A MESSAGE HAS BEEN RECEIVED FROM THE PI REQUESTING FOR A STATE CHANGE,
    RETURN FROM THIS FUNCTION WITH THE MESSAGE.
*/
std::string * Receiving::mainLoop() {
    /* Return the string requesting the next state change */
    while (1) {
        return nullptr;
    }
    return nullptr;
}
