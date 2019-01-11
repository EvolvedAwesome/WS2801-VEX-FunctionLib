# WS2801-VEX-FunctionLib
Provides a RobotC (Cortex) software interface layer for communicating with and controlling the SPI-based WS2801 individually addressable LED strips through a bit-banged communication protocol on the VEX cortex.

Usage example in the examples folder.

The library uses a simple structure typedef'ed as "ws2801_data" in order to provide all the necessary data to the library functions, and to make it possible to use multiple Strips in the same programme. 

## Functions used:
void ws2801_sendByte(ws2801_data *stripData, ubyte value);
void ws2801_init(ws2801_data *stripData, ubyte length);
void ws2801_init(ws2801_data *stripData, ubyte length, tSensors clockPin, tSensors dataPin);
void ws2801_sendFrame(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue);
void ws2801_setStripColour(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue);
