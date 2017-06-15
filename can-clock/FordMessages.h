#ifndef __FORD_MESSAGES_H_
#define __FORD_MESSAGES_H_

#include "CANMessage.h"

#define START_COUNT 8
#define MSG_COUNT 4
#define TEXT_COUNT 12
#define TPMS_COUNT 3
#define TPMS_INIT_COUNT 1

#define TPMS_FRONT 0
#define TPMS_REAR 1
#define TPMS_TEMP 2
#define TPMS_INIT 3

CANMessage start[START_COUNT];
CANMessage cycle[MSG_COUNT];
CANMessage text[TEXT_COUNT];
CANMessage metric;

CANMessage tpms[TPMS_COUNT+TPMS_INIT_COUNT];

void initStartMessages()
{
  start[0].set( 0, 100, 0, 0x50c, 3, 0x0C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 );
  start[1].set( 0, 250, 0, 0x3e8, 8, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00 );
  start[2].set( 0,  50, 0, 0x3ef, 8, 0x32, 0x32, 0x32, 0x32, 0x03, 0x00, 0x00, 0x00 );
  start[3].set( 0,  50, 0, 0x3f2, 8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x60, 0x00, 0x00 );
  start[4].set( 0, 100, 0, 0x50c, 3, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 );
  start[5].set( 0,  50, 0, 0x3f2, 8, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00 );
  start[6].set( 0,  50, 0, 0x3f1, 8, 0xF5, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 );
  start[7].set( 0, 100, 0, 0x50c, 3, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 );
}

void initCycleMessages()
{
  cycle[0].set( 0,   0,  500, 0x50c, 3, 0x11, 0x02, 0x00, 0xBE, 0xBE, 0xBE, 0xBE, 0xBE );
  cycle[1].set( 0, 400, 1000, 0x3e8, 8, 0x0F, 0x00, 0x29, 0x04, 0x00, 0x00, 0x00, 0x00 );
  cycle[2].set( 0, 450, 1000, 0x3ef, 8, 0x32, 0x32, 0x32, 0x32, 0x03, 0x00, 0x00, 0x20 );
  cycle[3].set( 0, 500, 1000, 0x3f2, 8, 0x12, 0x01, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00 );
}

void initTextMessages()
{
  text[ 0].set( 1000,   0, 500, 0x336, 8, 0x03, 0x01, 0x0A, 0x01, 0xFE, 0x00, 0x00, 0x00 );
  text[ 1].set( 1000,  50, 500, 0x324, 8, 0x01, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00 );
  text[ 2].set( 1000, 100, 500, 0x337, 8, 0x06, 0x20,  ' ',  '@',  ' ',  '@',  ' ', 0x00 );
  text[ 3].set( 1000, 200, 500, 0x336, 8, 0x03, 0x01, 0x05, 0x03, 0x03, 0x00, 0x00, 0x00 );
  text[ 4].set( 1000, 225, 500, 0x324, 8, 0x03, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00 );
  text[ 5].set( 1000, 250, 500, 0x337, 8, 0x10, 0x2B,  ' ',  ' ',  ' ',  '@',  ' ',  ' ' );
  text[ 6].set( 1000, 275, 500, 0x337, 8, 0x21,  ' ',  'M',  'e',  'r',  'c',  '@',  'u' );
  text[ 7].set( 1000, 300, 500, 0x337, 8, 0x22,  'r',  'y',  ' ',  ' ',  ' ',  ' ',  ' ' );
  text[ 8].set( 1000, 325, 500, 0x337, 8, 0x23,  ' ',  ' ',  ' ',  ' ',  ' ',  '@',  ' ' );
  text[ 9].set( 1000, 350, 500, 0x337, 8, 0x24,  ' ',  ' ',  'M',  'a',  'r',  'i',  'n' );
  text[10].set( 1000, 375, 500, 0x337, 8, 0x25,  'e',  'r',  ' ',  ' ',  ' ',  ' ',  ' ' );
  text[11].set( 1000, 400, 500, 0x337, 8, 0x26,  ' ',  ' ', 0x00, 0x00, 0x00, 0x00, 0x00 );
}

void initMetricMessage()
{
  metric.set( 0, 0, 0, 0x129, 8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
}

void initTpmsMessages()
{
  tpms[0].set( 0,   0,  5000, 0x726, 8, 3, 0x22, 0x41, 0x40, 0x00, 0x00, 0x00, 0x00 );  // Front
  tpms[1].set( 0, 200,  5000, 0x726, 8, 3, 0x22, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00 );  // Rear
  tpms[2].set( 0, 400, 10000, 0x726, 8, 3, 0x22, 0x41, 0x60, 0x00, 0x00, 0x00, 0x00 );  // Temperature
  tpms[3].set( 0,   0,     0, 0x726, 8, 2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 );  // Initialization
}

#define TIRE_FL 0
#define TIRE_FR 1
#define TIRE_RL 2
#define TIRE_RR 3
#define TIRES 4

#endif // __FORD_MESSAGES_H_
