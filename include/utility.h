#ifndef UTILITY_H
#define UTILITY_H

#include <Arduino.h>
#include <Arduboy2.h>  //注意 这里使用被阉割的图形库，只有绘图功能，并非通用的版本
#include <PID_v1.h>
#include "config.h"
#include "bit_map.h"
#include "memory.h"

// define in utility.cpp
extern void(* resetFunc) (void);
int getRotary();
void CheckLastButton();
byte QueryMenuObject();
uint16_t denoiseAnalog (byte port);
float getChipTemp();
uint16_t getVCC();
uint16_t getVIN();
float calculateTemp(float t);
void Thermostat(bool mode);
void beep();
void setRotary(int rmin, int rmax, int rstep, int rvalue);
void SENSORCheck(bool mode);
void ROTARYCheck();
void SLEEPCheck();
void SetOLEDLightLevel(uint8_t level);

#endif