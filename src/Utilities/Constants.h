#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

namespace CONSTANTS {
    float const VCC = 5.0;
}

namespace COMMUNICATION {
    namespace EMGCOMM {
        double const REFERENCE_VOLTAGE = 1.2;
        double const RESOLUTION_ADC    = 1024.0;
    }
    namespace FSRCOMM {
        float const BRAKE_THRESHOLD   = 12;    // threshold above which brakes are activated
        float const PULLDOWN_RESISTOR = 10000; // value of pulldown resistor (in Ohms)
        float const CURVE_CONSTANT    = 9000;  // constant given by resistance-pressure curve (1/2 inch medium resistance thrumode) https://www.sensitronics.com/product-res/half-inch-thru-mode-fsr/docs/half-inch-thru-mode-medium-res.pdf
    }
    namespace MAECOMM {

    }
    namespace PICOMM {
        namespace META {
            int const          BAUDRATE = 9600;
            char const * const ENDTAG  = "\n";
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
    }
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
    enum PWM {
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
    namespace FSR {
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