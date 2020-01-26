#include <communication.h>
#include <stdlib.h>
#include <Arduino.h>
#include <constants.h>
#include "document.h"
#include "rapidjson/prettywriter.h"


using namespace rapidjson;

Communication::Communication(int BAUDRATE) : BAUDRATE(BAUDRATE) {}

/*  Setup:
        Begins the serial communication channel and flushes the serial buffer before anything is sent/received.
*/
void Communication::setup() {
    Serial.begin(this->BAUDRATE);
    Serial.flush();
}

void Communication::handshake() {
    while (Serial.available() < 2) {
        // Serial.write(4);
            /*do nothing*/
    }
    // Serial.write(4);
    this->read_message();
    // Check that the handshake has been successfully performed
    if ((this->order == 0x00) && (this->param == 0xFF)) Serial.write(HANDSHAKE);
}

// void Communication::read_message() {
//     // buffer has to be at least two bytes long
//     while (Serial.available() < 2) { /*do nothing*/ }

//     this->order = Serial.read();
//     this->param = Serial.read();
// }

int Communication::get_order() {
    return this->order;
}

int Communication::get_param() {
    return this->param;
}

void Communication::send_confirmation() {
    Serial.write(MSG::OK);
}


String Communication::readRawMessage() const {
    return Serial.readStringUntil(*(this->END_TAG));
}

// Document * const Communication::readMessage() const {
//     char const * const msg = this->readRawMessage().toCharArray;
//     Document * doc = new Document();
//     return &(doc->Parse(msg));
// }

Document * const Communication::readMessage() const {
    char const * const msg = this->readRawMessage().toCharArray;
    Document * doc = new Document();
    return &(doc->Parse(msg));
}

String * const Communication::getStringFromMessage(Document * const json, String key) const {
    if (!(json && key && json->HasMember(key.toCharArray) && json[key.toCharArray].IsString())) return nullptr;
    return json[key.toCharArray].GetString();
}
bool * const Communication::getBoolFromMessage(Document * const json, String key) const {
    if (!(json && key && json->HasMember(key.toCharArray) && json[key.toCharArray].IsBool())) return nullptr;
    return json[key.toCharArray].GetBool();
}
int * const Communication::getIntFromMessage(Document * const json, String key) const {
    if (!(json && key && json->HasMember(key.toCharArray) && json[key.toCharArray].IsInt())) return nullptr;
    return json[key.toCharArray].GetInt();
}
double * const Communication::getDoubleFromMessage(Document * const json, String key) const {
    if (!(json && key && json->HasMember(key.toCharArray) && json[key.toCharArray].IsDouble())) return nullptr;
    return json[key.toCharArray].GetDouble();
}
void * const Communication::getArrayFromMessage(Document * const json, String key) const {
    if (!(json && key && json->HasMember(key.toCharArray) && json[key.toCharArray].IsArray())) return nullptr;
    return json[key.toCharArray];
}