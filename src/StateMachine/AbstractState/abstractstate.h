#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H



#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>



class AbstractState {
    private:
        AbstractState() = delete;
        AbstractState(AbstractState const &) = delete;
        AbstractState(AbstractState const &&) = delete;
        void operator=(AbstractState const &) = delete;
        void operator=(AbstractState const &&) = delete;

        unsigned int const ID = -1;
        std::vector<std::pair<std::string,AbstractState *>> * keysAndStates;

    protected:
        AbstractState(unsigned int const ID) : ID(ID) {}

    public:
        virtual ~AbstractState() {}

        unsigned int getID() const;

        bool setKeysAndStates(std::vector<std::pair<std::string,AbstractState *>> * const keysAndStates);

        virtual std::string * mainLoop() = 0;
        AbstractState * switchState(std::string const & message);
};



#endif