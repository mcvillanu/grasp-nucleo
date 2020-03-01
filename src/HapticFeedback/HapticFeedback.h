#ifndef HAPTIC_H
#define HAPTIC_H

#include <Arduino.h>

class Haptic {
    public:
    /**
     * Default constructor for the haptic feedback
     * */
    Haptic(int pin);

    void setup();

    void haptic(int power, int time);

    private:
    int pin;

};

#endif