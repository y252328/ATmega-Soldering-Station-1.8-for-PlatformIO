#ifndef MEMORY_H
#define MEMORY_H

#include <Arduino.h>
#include <Arduboy2.h>  //注意 这里使用被阉割的图形库，只有绘图功能，并非通用的版本
#include "config.h"
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
*/
void SetTextColor(bool color);
void ProgressBar(int i, int a, int b, byte x, byte y, byte w, byte h, bool c);
void setRotary(int rmin, int rmax, int rstep, int rvalue);
int getRotary();
void CheckLastButton();

void CheckEEPROM();
void UpdateEEPROM();
void GetEEPROM();
void GetEEPRomTip(byte n);
void PutEEPRomTip(byte n);
void DelEEPRomTip(byte n);
void ViewEEPRom();

#endif