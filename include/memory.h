#ifndef MEMORY_H
#define MEMORY_H

#include <Arduino.h>
#include <Arduboy2.h>  //注意 这里使用被阉割的图形库，只有绘图功能，并非通用的版本
#include "config.h"
#include "gui.h"

void CheckEEPROM();
void UpdateEEPROM();
void GetEEPROM();
void GetEEPRomTip(byte n);
void PutEEPRomTip(byte n);
void DelEEPRomTip(byte n);
void ViewEEPRom();

#endif