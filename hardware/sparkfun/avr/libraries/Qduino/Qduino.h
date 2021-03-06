/**************************************************************************
 *                                                                         *
 * Qduino Mini library w/MAX1704* Driver & RGB PWM control                 *
 *                                                                         *
 * Forked From:                                                            *
 * Matthew Newberry                                                        *
 * mattnewberry@me.com                                                     *
 *                                                                         *
 ***************************************************************************
 *                                                                         * 
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU License.                                  *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU License V2 for more details.                                        *
 *                                                                         *
 ***************************************************************************/

#include "Arduino.h"

#ifndef _Qduino_h
#define _Qduino_h

#define MAX1704_ADDR            0x36
#define MAX1704_SOC             0x04
#define MAX1704_VERSION         0x08
#define MAX1704_POWER_ON_RESET  0x54
#define MAX1704_QUICK_START     0x40
#define MAX1704_CONFIG          0x0C
#define MAX1704_COMMAND         0xFE
#define MAX1704_ALERT_LEVEL     0x97

class qduino{
    
public:
    void setup();
    void setRGB(int r, int g, int b);
    void setRGB(String color);
    void rainbow(int duration);
    void ledOff();
    
private:
    
};

class fuelGauge{
    
public:
  int chargePercentage();
  void setup();
  void reset();
  char getVersion();
  void setThreshold(uint8_t level);
  int currentThreshold();
  boolean inSleep();
  boolean inAlert();
  void goToSleep();
  void wakeUp();
  
    
private:
  void performCommand(byte address, int value);
  void readFrom(byte address, byte &msb, byte &lsb);
};

#endif
