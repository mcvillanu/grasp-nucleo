#ifndef HAPTIC_H
#define HAPTIC_H

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