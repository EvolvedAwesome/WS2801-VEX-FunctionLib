/*
 * WS2801_FunctionLib.c
 *
 * Provides a RobotC (Cortex) software interface layer for communicating with and
 * controlling the SPI-based ws2801 individually addressable LED strips through
 * a bit-banged communication protocol on the VEX cortex.
 *
 * Author: John Cole
 * Created On: 11/01/2019
 */

void ws2801_sendByte(ws2801_data *stripData, ubyte value) {
#if DEBUG
  writeDebugStreamLine("Writing ubyte value: %d.", value);
#endif
  // Important that least-significant-bit is last
#if WS2801_USE_ROBOTC_BITBANG
  ShiftOut(stripData->dataPin, stripData->clockPin, false, value, 1);
#else
  for(ubyte i = 128; i >= 1; i = i / 2)
  {
    // Send the i component of the data
    SensorValue[stripData->dataPin] = value & i;
    // The SPI interface reads the data in on the rising edge of the clock.
    SensorValue[stripData->clockPin] = 1;
    SensorValue[stripData->clockPin] = 0;
  }
#endif
}

void ws2801_init(ws2801_data *stripData, ubyte length) {
#if DEBUG
  writeDebugStreamLine("Initalizing the WS2801 strip with a length %d.", length);
#endif
  stripData->length = length;
  stripData->clockPin = WS2801_CLOCK_PIN;
  stripData->dataPin = WS2801_DATA_PIN;
}

void ws2801_init(ws2801_data *stripData, ubyte length, tSensors clockPin, tSensors dataPin) {
#if DEBUG
  writeDebugStreamLine("Initalizing the WS2801 strip with a length %d.", length);
#endif
  stripData->length = length;
  stripData->clockPin = clockPin;
  stripData->dataPin = dataPin;
}

void ws2801_sendFrame(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue) {
#if DEBUG
  writeDebugStreamLine("Sending Data frame with R:%d, G:%d, B:%d.", red, green, blue);
#endif
  // We should be able to dumbly send 3 bytes of data.
#if WS2801_USE_GBR
  ws2801_sendByte(stripData, green);
  ws2801_sendByte(stripData, blue);
  ws2801_sendByte(stripData, red);
#else // WS2801_USE_RGB
  ws2801_sendByte(stripData, red);
  ws2801_sendByte(stripData, green);
  ws2801_sendByte(stripData, blue);
#endif
}

void ws2801_setStripColour(ws2801_data *stripData, ubyte red, ubyte green, ubyte blue) {
#if DEBUG
  writeDebugStreamLine("Setting whole strip colour to R:%d, G:%d, B:%d.", red, green, blue);
#endif
  // Enumerate through the whole strip length and send that many frame packets
  // with the frame data.
  for(ubyte i = 0; i <= stripData->length; i++) {
    ws2801_sendFrame(stripData, red, green, blue);
  }
}
