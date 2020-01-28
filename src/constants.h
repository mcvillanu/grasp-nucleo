#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

namespace COMMUNICATION {
    int const          BAUDRATE = 9600;
    char const * const END_TAG  = "\n";
}

enum JSON_TYPES {
    DNE = -1,
    STR = 0,
    BLN = 1,
    INT = 2,
    DBL = 3,
    ARR = 4
};

enum MSG {
    OK   = 1,
    STOP = 2
};

enum STATE {
    ACTIVE         = 0,
    SAFE_SHUTDOWN  = 1
};

enum GRIPS {
    GRIP_HAMMER = 0,
    GRIP_PINCH  = 1,
    GRIP_BALL   = 2,
    GRIP_C      = 3,
    GRIP_FLAT   = 4
};

namespace PINS {
    /* Fingers */
    const int THUMB_PWM  = PA1;
    const int INDEX_PWM  = PB0;
    const int MIDDLE_PWM = PA15;
    const int RING_PWM   = PA6;
    const int PINKY_PWM  = PA11;


    /* Wrist */
    const int WRIST_STEP = PB6;
    const int WRIST_DIR  = PB15;
    const int WRIST_M0   = PA9;
    const int WRIST_M1   = PC7;


    /* EMG */
    const int EMG_SIG    = PC12;
}

namespace VARS {
    const int WRIST_RPM = 100;
}
#endif
