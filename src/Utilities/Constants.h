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
    enum MAECOMM {
        RX = PA12,
        TX = PB12 
    };
    namespace PICOMM {
        namespace META {
            int          const BAUDRATE = 9600;
            char const * const ENDTAG   = "\n";
        };
        enum MSG {
            OK   = 1,
            STOP = 2
        };
    }
};

namespace UTILITIES {
    namespace ACCESSORIES {
    };
    namespace JSON {
        namespace INTERPRETER {
            namespace DESERIALIZER {
                enum RESOLVE_TYPES {
                    UNRESOLVABLE = -1,
                    RESOLVED = 0,
                    RESOLVABLE = 1
                };
            };
            namespace SERIALIZER {

            };
        };
        namespace META {
            size_t const SIZE = 1024;
        };
        enum TYPES {
            DNE = -1,
            NIL = 0,
            STR = 1,
            BLN = 2,
            INT = 3,
            DBL = 4,
            ARR = 5,
            OBJ = 6
        };
    };
};

namespace GRIPS {
    const int GRIP_HAMMER = 0;
    const int GRIP_PINCH  = 1;
    const int GRIP_FLAT   = 2;
    const int GRIP_BALL   = 3;
    const int GRIP_C      = 4;
    const int GRIP_RESET  = 5;
}

namespace PINS {
    enum CHAN {
        THUMB_MOTOR  = 0,
        INDEX_MOTOR  = 1,
        MIDDLE_MOTOR = 2,
        RING_MOTOR   = 3,
        PINKY_MOTOR = 4
    };
    enum WRIST {
        WRIST_STEP = PB6,
        WRIST_DIR  = PA7,
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

namespace STATES {
    const int SAFETY_ON = 0;
    const int RECEIVING = 1;
    const int IN_GRIP = 2;
};

// change the values for the serial ports
namespace MAESTRO {
    const int SERIAL_ONE = 2;
    const int SERIAL_TWO = 3;
    const int DEVICE_NUMBER = 255;
    const int NO_RESET_PIN = 255;
    const bool CRC_ENABLED = false;
}

#endif