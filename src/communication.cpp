#include <communication.h>
#include <stdlib.h>
#include <Arduino.h>

Communication::Communication(int BAUDRATE) 
{
    // Maybe let use 9600 rate
    this->BAUDRATE = BAUDRATE;
    // Begin the serial on Nucleo
    Serial.begin(this->BAUDRATE);
    // Clear the serial buffer before we begin communication
    Serial.flush();
}

void Communication::handshake()
{
    while (Serial.available() < 2)
    {
        /*do nothing*/
    }
    read_message();
    // Check that the handshake has been successfully performed
    if (this->order == 0x00 && this->param == 0xFF)
    {
        Serial.write(OK);
    }
}

void Communication::read_message()
{
    while (Serial.available() < 2)
    {
        /*do nothing*/
    }
    
    this->order = Serial.read();
    this->param = Serial.read();
}

vector<int> Communication::get_order()
{
    return this->order;
}

vector<int> Communication::get_param()
{
    return this->param;
}