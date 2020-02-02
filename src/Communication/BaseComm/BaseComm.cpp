#include <Communication/BaseComm/BaseComm.h>



Base::Base(int const pin) : pin(pin) {}
int const Base::getPin() const {
    return this->pin;
}