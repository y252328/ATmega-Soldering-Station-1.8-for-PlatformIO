#ifndef UTILITY_H
#define UTILITY_H

#include <Arduino.h>
#include <Arduboy2.h>  //注意 这里使用被阉割的图形库，只有绘图功能，并非通用的版本
#include <PID_v1.h>
#include "config.h"
#include "bit_map.h"
#include "memory.h"
/*
extern Arduboy2 arduboy;
extern uint16_t  DefaultTemp;
extern uint16_t  SleepTemp  ;
extern uint8_t   BoostTemp  ;
extern uint8_t   Time2sleep ;
extern uint8_t   Time2off   ;
extern uint8_t   TimeOfBoost;
extern uint8_t   MainScrType;
extern bool      PIDenable  ;
extern bool      BeepEnable ;

extern uint8_t   CurrentTip ;
extern uint8_t   NumberOfTips;

extern byte LANG;
extern bool      FlipState;
extern byte UnderVoltage;
extern int Password;
extern bool RotaryD;

extern char TipName[];
extern float PTemp[];

extern bool lastbutton;

// start utility h
extern volatile int Count;
extern uint16_t  Vcc, Vin;
extern volatile uint8_t  a0, b0, c0, d0;
extern volatile bool     ab0;
extern volatile int      Count, CountMin, CountMax, CountStep;
extern volatile bool     handleMoved;

extern bool      InSleepMode ;
extern bool      InOffMode   ;
extern bool      InBoostMode ;
extern bool      InCalibMode ;
extern bool      IsWorky     ;
extern bool      BeepIfWorky ;
extern bool      TipIsPresent;
extern bool      FlipState ;

extern uint16_t  SetTemp, ShowTemp, gap, Step;
extern double Input, Output, RawTemp, Setpoint, CurrentTemp, ChipTemp;

extern double aggKp, aggKi, aggKd;
extern double consKp, consKi, consKd;

extern PID ctrl;

extern uint16_t  Time2settle;
extern uint8_t   SensorCounter;

extern uint32_t  Sleepmillis;
extern uint32_t  Boostmillis;
extern uint32_t  Buttonmillis;
extern uint8_t   GoneMinutes;
extern uint8_t   GoneSeconds;
extern uint8_t   SensorCounter;
*/
void ChangeTipScreen();
void SetupScreen();

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