#ifndef __SERVICE_H_
#define __SERVICE_H_

#include <Arduino.h>
#include <stdarg.h>

uint8_t decToBcd(const uint8_t val)
{
  return( (val/10*16) + (val%10) );
}

uint8_t bcdToDec(const uint8_t val)
{
  return( (val/16*10) + (val%16) );
}

String readSerialString()
{
  String inSerialData;
  char received = ' ';
  Serial.print(F("\n> "));
  while (received != '\r') {
      if (Serial.available() > 0) {
        received = Serial.read();
        inSerialData += received;
        Serial.print(received);
      }
  }
  inSerialData.trim();
  return(inSerialData);
}

#endif // __SERVICE_H_
