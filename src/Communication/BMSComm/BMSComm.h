#ifndef BMSCOMM_H
#define BMSCOMM_H

#include <Wire.h>
#include <Utilities/Constants.h>

/* Use to read the remaining battery capacity
-----
0x0F RemainingCapacity()
This read-word function returns the predicted remaining battery capacity.
0-65535, returns in mAh
-----

*/

class BMSComm {
    public:
        BMSComm();
        void setup();
        unsigned short int readCapacity();
};

#endif