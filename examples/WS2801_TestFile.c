/*
 * WS2801_TestFile.c
 *
 * A testing file for WS2801_FunctionLib.
 *
 * Author: John Cole
 * Created On: 11/01/2019
 */

#include "../WS2801_FunctionLib/WS2801_FunctionLib.h"

ws2801_data primaryLEDStrip;

task main {
  ws2801_init(primaryLEDStrip, 30, dgtl5, dgtl6);
  ws2801_sendFrame(primaryLEDStrip, 250, 250, 250);

  wait1Msec(2000);

  ws2801_setStripColour(primaryLEDStrip, 120, 120, 120);
}
