#include <Communication/BaseComm/BaseComm.h>

BaseComm::Base::Base(int const pin) : pin(pin) {}
int const BaseComm::Base::getPin() const {
    return this->pin;
}