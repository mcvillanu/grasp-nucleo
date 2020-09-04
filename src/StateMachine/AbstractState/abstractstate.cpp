#include <StateMachine/AbstractState/abstractstate.h>



unsigned int AbstractState::getID() const { return this->ID; }
bool AbstractState::setKeysAndStates(std::vector<std::pair<std::string,AbstractState *>> * const keysAndStates) {

    /*
    this code is if we want to validate the setup of the state machine connections 
    coming from this state.
    No functionality yet for checking non-unique strings or non-unique pointers
    */

    // if (alreadySet) return false;
    // else if (!keysAndStates || (keysAndStates->size() == 0)) return false;
    // else if (keysAndStates->size() == 1) {

    // }

    // this->keysAndStates = keysAndStates;
    // alreadySet = true;
    // return true;

    /*
        We are not checking for:
            - empty vectors
            - vectors of size 1 pointing back to themselves
            - vectors that contain non-unique strings
            - vectors that contain non-unique pointers
        (Due to time complexity reasons)
        (Please make sure the vector does not contain any of the above errors)
    */

    if (!keysAndStates) return false;
    this->keysAndStates = keysAndStates;
    return true;
}
AbstractState * AbstractState::switchState(std::string const & message) {
    // std::cout << "entering switchState\n" << std::flush;

    std::vector<std::pair<std::string,AbstractState *>>::iterator itr(this->keysAndStates->begin());
    for (; itr!=this->keysAndStates->end(); ++itr) if (itr->first == message) return itr->second;
    // std::cout << "incorrect key pair\n";

    // std::cout << "exiting switchState\n" << std::flush;
    // return nullptr;

    // std::cout << "asdf1\n" << std::flush;
    // std::cout << (*this->keysAndStates)[0].first << "\n" << std::flush;
    // std::cout << "asdf2\n" << std::flush;
    // return (*this->keysAndStates)[0].second;

    return nullptr;
}
