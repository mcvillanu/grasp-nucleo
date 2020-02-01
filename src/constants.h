#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>



namespace COMMUNICATION {
    namespace META {
        int const          BAUDRATE = 9600;
        char const * const END_TAG  = "\n";
    };
    enum JSON_TYPES {
        DNE = -1,
        NIL = 0,
        STR = 1,
        BLN = 2,
        INT = 3,
        DBL = 4,
        ARR = 5,
        OBJ = 6
    };
    enum MSG {
        OK   = 1,
        STOP = 2
    };
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
    enum FINGERS {
        THUMB_PWM  = PA1,
        INDEX_PWM  = PB0,
        MIDDLE_PWM = PA15,
        RING_PWM   = PA6,
        PINKY_PWM  = PA11
    };
    enum WRIST {
        WRIST_STEP = PB6,
        WRIST_DIR  = PB15,
        WRIST_M0   = PA9,
        WRIST_M1   = PC7
    };
    enum FSR {
        //TODO: Assign pins
        const int THUMB_FSR  = 0;
        const int INDEX_FSR  = 0;
        const int MIDDLE_FSR = 0;
        const int RING_FSR   = 0;
        const int PINKY_FSR  = 0;
    }
    enum EMG {
        EMGSIGNAL   = PC12
    };
};

namespace VARS {
    const int WRIST_RPM = 100;
};

#endif