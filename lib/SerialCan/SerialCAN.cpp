/**
 * \file        CoAmpCAN.cpp
 * \brief       Library for Co-Amp CAN_0 message communication.
 *
 * \authors     Nathan Brantly, Frank Cummins
 * \bug
 */

// INCLUDES
#include "SerialCAN.h"

// PRIVATE VARIABLES - NONE

// PRIVATE FUNCTION PROTOTYPES - NONE

// PUBLIC FUNCTION PROTOTYPES

/**
 * \brief High level method that initializes Co-Amp with default gain
 *
 * \param controllerConnected boolean to set gain and send start message when appropriate
 */
void CoAmpInitialize_S( uint8_t controllerConnected, uint8_t allChannelsGain)
{
        SerialCAN.begin(CAN_1000KBPS);
        delay(2500);
        if(!controllerConnected)
        {
                TransmitGainCANMsg_S(allChannelsGain);
                TransmitStartCANMsg_S();
        }
}


/**
 * \brief Transmits gain CAN_0 message to Co-Amp to set all channel gains
 *
 * \param allChannelsGain Gain value to set for all eight channels (i.e., 4, 6, 8, 10, or 12)
 */
void TransmitGainCANMsg_S( uint8_t allChannelsGain )
{
        // Construct the gain message (2 header messages + 8 channel messages)
        for ( uint8_t i = 0; i < NUM_EMG_CHANNELS + 2; i++ ) 
        {
                // Instantiate gain CAN_0 message object to transmit to Co-Amp
                // CAN_Frame gainCANMsg;

                // gainCANMsg.id = 0x150;      // Message ID
                // gainCANMsg.valid = true;
                // gainCANMsg.rtr = 0;
                // gainCANMsg.length = 5;      // Length
                uint32_t id = 0x150;
                uint8_t ext = 0;
                uint8_t len = 5;
                uint8_t* buf = new uint8_t[5];

                // Set each data byte in gain CAN_0 message object
                // gainCANMsg.data[0] = 0x04;
                buf[0] = 0x04;
                switch(i)
                {
                        case 0:
                                // gainCANMsg.data[1] = 0x02;
                                // gainCANMsg.data[2] = 0xFE;
                                // gainCANMsg.data[3] = 0x03;
                                // gainCANMsg.data[4] = 0xE8;
                                buf[1] = 0x02;
                                buf[2] = 0xFE;
                                buf[3] = 0x03;
                                buf[4] = 0xE8;
                                break;
                
                        case 1:
                                // gainCANMsg.data[1] = 0x03;
                                // gainCANMsg.data[2] = 0xFE;
                                // gainCANMsg.data[3] = 0x00;
                                // gainCANMsg.data[4] = 0x10;
                                buf[1] = 0x03;
                                buf[2] = 0xFE;
                                buf[3] = 0x00;
                                buf[4] = 0x10;
                                break;

                        default:
                                // gainCANMsg.data[1] = 0x01;
                                // gainCANMsg.data[2] = i - 1;             // Channel index
                                // gainCANMsg.data[3] = 0x00;
                                // gainCANMsg.data[4] = allChannelsGain;   // Channel gain
                                buf[1] = 0x01;
                                buf[2] = i - 1;             // Channel index
                                buf[3] = 0x00;
                                buf[4] = allChannelsGain;   // Channel gain
                                break;
                }

                // Transmit Co-Amp gain CAN_0 message
                // CAN_0.write( gainCANMsg );
                SerialCAN.sendMsgBuf(id, ext, len, buf);
        }
}

/**
 * \brief Transmit start CAN_0 message to Co-Amp to begin streaming EMG data
 */
void TransmitStartCANMsg_S( void )
{
        // Instantiate start CAN_0 message object to transmit to Co-Amp
        // CAN_Frame startCANMsg; 

        // startCANMsg.id = 0x150;         // Message ID
        // startCANMsg.valid = true;
        // startCANMsg.rtr = 0;
        // startCANMsg.length = 2;         // Length
        // startCANMsg.data[0] = 0x50;     // Start message
        // startCANMsg.data[1] = 0x01;

        // // Transmit Co-Amp start CAN_0 message
        // CAN_0.write( startCANMsg );

        // New Serial Version (Seeed Library)
        uint32_t id = 0x150;
        uint8_t ext = 0;
        uint8_t len = 2;
        uint8_t* buf = new uint8_t[2];
        buf[0] = 0x50;
        buf[1] = 0x01;
        SerialCAN.sendMsgBuf(id, ext, len, buf);
        delete buf;
}

/**
 * \brief Receive CAN_0 EMG messages from Co-Amp
 *
 * \param a_EMGSample Pointer to EMG sample array
 * \param p_numEMGSamps Pointer to number of EMG samples received counter to increment
 * \return 1 if all three EMG sample Co-Amp CAN_0 messages received, 0 if not
 */
uint8_t CoAmpCANAvailable_S( uint16_t *a_EMGSample, uint8_t *p_numEMGSamples )
{
        uint8_t available = 0;

        // If there is a CAN_0 message in the buffer
        // if ( CAN_0.available() )
        if ( SerialCAN.checkReceive())
        {
                // Instantiate EMG CAN_0 message object to read from Co-Amp
                // CAN_Frame emgCANMsg;    

                // Read Co-Amp EMG CAN_0 message
                // emgCANMsg = CAN_0.read();

                // Load the message into the EMG sample array
                // switch ( emgCANMsg.id )
                uint8_t* len;
                uint8_t* buf;
                SerialCAN.readMsgBuf(len, buf);
                switch (SerialCAN.getCanId())
                {
                case 0x451:
                        // a_EMGSample[0] = ( (uint16_t)emgCANMsg.data[1] << 8 ) | emgCANMsg.data[2];
                        // a_EMGSample[1] = ( (uint16_t)emgCANMsg.data[3] << 8 ) | emgCANMsg.data[4];
                        // a_EMGSample[2] = ( (uint16_t)emgCANMsg.data[5] << 8 ) | emgCANMsg.data[6];
                        a_EMGSample[0] = ( (uint16_t)buf[1] << 8 ) | buf[2];
                        a_EMGSample[1] = ( (uint16_t)buf[3] << 8 ) | buf[4];
                        a_EMGSample[2] = ( (uint16_t)buf[5] << 8 ) | buf[6];
                        break;

                case 0x452:
                        // a_EMGSample[3] = ( (uint16_t)emgCANMsg.data[1] << 8 ) | emgCANMsg.data[2];
                        // a_EMGSample[4] = ( (uint16_t)emgCANMsg.data[3] << 8 ) | emgCANMsg.data[4];
                        // a_EMGSample[5] = ( (uint16_t)emgCANMsg.data[5] << 8 ) | emgCANMsg.data[6];
                        a_EMGSample[3] = ( (uint16_t)buf[1] << 8 ) | buf[2];
                        a_EMGSample[4] = ( (uint16_t)buf[3] << 8 ) | buf[4];
                        a_EMGSample[5] = ( (uint16_t)buf[5] << 8 ) | buf[6];
                        break;

                case 0x453:
                        // a_EMGSample[6] = ( (uint16_t)emgCANMsg.data[1] << 8 ) | emgCANMsg.data[2];
                        // a_EMGSample[7] = ( (uint16_t)emgCANMsg.data[3] << 8 ) | emgCANMsg.data[4];
                        a_EMGSample[6] = ( (uint16_t)buf[1] << 8 ) | buf[2];
                        a_EMGSample[7] = ( (uint16_t)buf[3] << 8 ) | buf[4];

                        // Increment the counter for timing purposes
                        (*p_numEMGSamples)++;
                        
                        // Raise the available flag to indicate that a new packet has been received
                        available = 1;
                        break;
                }
        }

        return available;
}
