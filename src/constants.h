#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

namespace COMMUNICATION {
    int const BAUDRATE;
    char const * const END_TAG = "\n";
}

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
