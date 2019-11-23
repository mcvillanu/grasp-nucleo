#ifndef CONSTANTS_H
#define CONSTANTS_H

<<<<<<< HEAD
=======
#include <Arduino.h>
>>>>>>> 7feec4be8ad5e64bfa1bb97e0c072d7b44e0a0a2
namespace PINS {
    const int THUMB_PWM = PA1;
    const int INDEX_PWM = PB0;
    const int MIDDLE_PWM = PA15;
    const int RING_PWM = PA6;
    const int PINKY_PWM = PA11;

    const int WRIST_STEP = PB6;
    const int WRIST_DIR = PB15;
    const int WRIST_M0 = PA9;
    const int WRIST_M1 = PC7;

    const int EMG_SIG = PC12;
}

namespace VARS {
    const int WRIST_RPM = 100;
}
#endif