#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

/* Communication:
 * All constants related to Serial communication between the Nucleo and the Raspberry Pi.
 * 
 * Meta:
 * Meta information related to the initialization and overall operation of the serial communication.
 * 
 * JSON Types:
 * The different types of values the JSON values may be represented as:
 *      1)  Does Not Exist:     If the JSON being searched through does not have the key it's being searched against.
 *      2)  Nil:                If the JSON key has a Null value.
 *      3)  Str:                A std::string.
 *      4)  Bln:                A boolean.
 *      5)  Int:                An integer.
 *      6)  Dbl:                A double.
 *      7)  Arr:                An array.
 *      8)  Obj:                A nested object.
 * 
 * Msg:
 * Standardized messaging signals (since it's standardized, the same enum values should be represented in the Python code as well).
 */
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

/* State:
 * The different states that the arm can be in.
 * Behaviour in different states should be different as dictated by the necessities of said state.
 */
enum STATE {
    ACTIVE         = 0,
    SAFE_SHUTDOWN  = 1
};

/* Grips:
 * Honestly, this should be perfectly self-explanatory, why are you even looking for an explanation for this enum? It's literally in the name lol...
*/
enum GRIPS {
    GRIP_HAMMER = 0,
    GRIP_PINCH  = 1,
    GRIP_BALL   = 2,
    GRIP_C      = 3,
    GRIP_FLAT   = 4
};

/* Pins:
 * A namespace relating to all the GPIO Pins leaving the Nucleo.
 * Separated into categories depending on the purpose of that pin.
 */
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
    enum EMG {
        EMG_SGNL   = PC12
    };
};

/* Vars:
 * I guess the name explains itself...?
 */
namespace VARS {
    const int WRIST_RPM = 100;
};

#endif