#include <Communication/BMSComm/BMSComm.h>

BMSComm::BMSComm() {}

void BMSComm::setup() {
    Wire.begin();
}
/*
This read-word function returns the predicted remaining battery capacity.
0-65535, returns in mAh
*/
unsigned short int BMSComm::readCapacity() {
    char x0 = 0;
    char x1 = 0;
    Wire.beginTransmission(COMMUNICATION::BMSCOMM::ADDRESS);
    Wire.write(COMMUNICATION::BMSCOMM::COMMAND);
    Wire.endTransmission();

    Wire.requestFrom(COMMUNICATION::BMSCOMM::ADDRESS, 2);
    if (Wire.available()<=2) {  // 
        // read least sig byte first (I think)
        x0 = Wire.read(); // Reads the data from the register
        x1 = Wire.read();
    }
    
    return x0 | x1 << 8;
}

