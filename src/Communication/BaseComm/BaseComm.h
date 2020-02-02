#ifndef BASECOMM_H
#define BASECOMM_H

class Base {
    protected:
        int const pin;
    
    public:
        Base(int const pin);

        virtual void setup() = 0;
        int const getPin() const;
};

#endif