/*
 * WS2801_FunctionLib.h
 *
 * Provides a RobotC (Cortex) software interface layer for communicating with and
 * controlling the SPI-based ws2801 individually addressable LED strips through
 * a bit-banged communication protocol on the VEX cortex.
 *
 * Author: John Cole
 * Created On: 11/01/2019
 */

#ifndef WS2801_FUNCTIONLIB_H_
#define WS2801_FUNCTIONLIB_H_

#define WS2801_CLOCK_PIN dgtl5
#define WS2801_DATA_PIN dgtl6

#define WS2801_USE_ROBOTC_BITBANG 0

#define WS2801_USE_RGB 0
#define WS2801_USE_GBR 1

#define DEBUG 1

typedef struct _ws2801_data {
  ubyte length;
  tSensors clockPin;
  tSensors dataPin;
} ws2801_data;

void ws2801_sendByte(ws2801_data *stripData, ubyte value);
void ws2801_init(ws2801_data *stripData, ubyte length);
void ws2801_init(ws2801_data *stripData, ubyte length, tSensors clockPin, tSensors dataPin);
void ws2801_sendFrame(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue);
void ws2801_setStripColour(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue);

#include "WS2801_FunctionLib.c"

#endif
