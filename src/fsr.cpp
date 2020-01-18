#include "fsr.h"
#include <Arduino.h>

Fsr::Fsr(int pin) {
    this->pin = pin;
}

void Fsr::setup() {
    pinMode(this->pin, INPUT);
}

float Fsr::getPsi() {
    /* Useful link: https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr
     * Given pressure F
     * pulldown resistance R
     * resistance vs pressure curve constant C
     * supply voltage Vcc = 5 V
     * voltage reading V_o
     * We have F = C / R  * 1 / (Vcc / V_o - 1)
    */
    float voltage = (float) analogRead(pin) * 5.0 / 1023.0;
    return curveConst / pulldown / (5.0 / voltage - 1);
}