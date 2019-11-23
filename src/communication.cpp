#include <communication.h>
#include <stdlib.h>
#include <Arduino.h>
#include <constants.h>

Communication::Communication(int BAUDRATE) {
    // Maybe let use 9600 rate
    this->BAUDRATE = BAUDRATE;
    // Begin the serial on Nucleo
}

void Communication::setup() {
    Serial.begin(this->BAUDRATE);
    // Clear the serial buffer before we begin communication
    // Serial.flush();
}

void Communication::handshake() {
    while (Serial.available() < 2) {
        Serial.write(4);
            /*do nothing*/
    }
    // Serial.write(4);
    this->read_message();
    // Check that the handshake has been successfully performed
    if ((this->order == 0x00) && (this->param == 0xFF)) Serial.write(HANDSHAKE);
}

void Communication::read_message() {
    // buffer has to be at least two bytes long
    while (Serial.available() < 2) { /*do nothing*/ }

    this->order =Serial.read();
    this->param =Serial.read();
}

int Communication::get_order() {
    return this->order;
}

int Communication::get_param() {
    return this->param;
}

void Communication::send_confirmation() {
    Serial.write(OK);
}
