#include "fsrMatrix.h"
#include <Arduino.h>
#include <./Utilities/Constants.h>

FSRMatrix::FSRMatrix(){
    initPins();
}

void FSRMatrix::initPins(){
    pinMode(PINS::FSR::MATRIX::PIN_ADC_INPUT, INPUT);
    pinMode(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_DATA, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_CLOCK, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_0, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_1, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_2, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_0, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_1, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_ADC_INPUT, INPUT);
    pinMode(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_DATA, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_CLOCK, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_0, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_1, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_2, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_0, OUTPUT);
    pinMode(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_1, OUTPUT);
}

void FSRMatrix::setRow(int rowNumber)
{
    //everything inside this if statement is to switch from one mux to another
    if ((rowNumber % ROWS_PER_MUX) == 0) //We've reached channel 0 of a mux IC, so disable the previous mux IC, and enable the next mux IC
    {
        digitalWrite(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_0 + current_enabled_mux, HIGH); //Muxes are enabled using offset from MUX_INHIBIT_0. This is why mux inhibits MUST be wired to consecutive Arduino pins!
        current_enabled_mux++;
        if (current_enabled_mux >= MUX_COUNT)
        {
            current_enabled_mux = 0;
        }
        digitalWrite(PINS::FSR::MATRIX::PIN_MUX_INHIBIT_0 + current_enabled_mux, LOW); //enable the next mux, active low
    }
    //this for loop is to iterate through the 8 pins on the current multiplexer is called in the main loop to iterate through the rows
    for (int i = 0; i < CHANNEL_PINS_PER_MUX; i++)
    {
        //x: the number from which to read.
        //n: which bit to read, starting at 0 for the least-significant (rightmost) bit.
        //bitRead(x , n)
        if (bitRead(rowNumber, i))
        {
            digitalWrite(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_0 + i, HIGH);
        }
        else
        {
            digitalWrite(PINS::FSR::MATRIX::PIN_MUX_CHANNEL_0 + i, LOW);
        }
    }
}

void FSRMatrix::shiftColumn(bool isFirst)
{
    if (isFirst)
    {
        digitalWrite(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_DATA, HIGH);
    }
    digitalWrite(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_CLOCK, HIGH);
    digitalWrite(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_CLOCK, LOW);
    if (isFirst)
    {
        digitalWrite(PINS::FSR::MATRIX::PIN_SHIFT_REGISTER_DATA, LOW);
    }
}

void FSRMatrix::read(){
    for (int i = 0; i < FSR_MATRIX_ROW_COUNT; i++)
    {
        //read at the current row, starting at zero
        setRow(i);
        shiftColumn(true);
        shiftColumn(false); //with SR clks tied, latched outputs are one clock behind

        for (int j = 0; j < FSR_MATRIX_COLUMN_COUNT; j++)
        {
            //read at the current column starting 0, and iterate through all columns before skipping to the next row
            int rawReading = analogRead(PINS::FSR::MATRIX::PIN_ADC_INPUT);

            //shift columns until we get to the next, just sets the clock and then low to keep shifting the bit
            shiftColumn(false);

            Serial.print(rawReading);
            Serial.print(" ");
        }
    }
    Serial.println();
}