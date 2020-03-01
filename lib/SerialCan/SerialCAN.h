/**
 * \file CoAmpCAN.h
 * \brief Library for Co-Amp CAN message communication.
 * TODO: Should be an interface implemented as an abstract class.
 *
 * \author Nathan Brantly
 * \bug
 */

#ifndef COAMPCAN_H
#define COAMPCAN_H

// INCLUDES
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include <SPI.h>
#include "mcp_can.h"

// CONSTANTS/MACROS
#define NUM_EMG_CHANNELS    8
#define DEFAULT_COAMP_GAIN	8
#define COAMP_ONLY 			0
#define CONTROLLER_CONNECTED 1
#define COAMP_FRAME_INCREMENT 50

// TYPES

// CLASSES

// FUNCTION PROTOTYPES
const int SPI_CS_PIN = 9;

MCP_CAN SerialCAN(SPI_CS_PIN);                                    // Set CS pin
void CoAmpInitialize_S( uint8_t controllerConnected, uint8_t allChannelsGain);
void TransmitGainCANMsg_S( uint8_t allChannelsGain );
void TransmitStartCANMsg_S( void );
uint8_t CoAmpCANAvailable_S( uint16_t *a_EMGSample, uint8_t *p_numEMGSamples );

#endif /* COAMPCAN_H */
