#ifndef GUI_H
#define GUI_H

#include <Arduino.h>
#include "config.h"
#include "memory.h"
#include "utility.h"
#include "curve_fitting.h"
#include "lang.h"
// draws the main screen
void MainScreen();
void DrawNumRect(byte x, byte y, byte size, int n);

//绘制状态条
void DrawStatusBar(bool color);

//设置画笔颜色
void SetTextColor(bool color);

// setup screen
void SetupScreen();

//设置滚轮方向
void RotarySet();

//显示设置菜单
// tip settings screen
void ScreenSet();

//预设设置菜单
// tip settings screen
void TipScreen();

//温控设置菜单
// temperature settings screen
void TempScreen();

//定时器设置菜单
// timer settings screen
void TimerScreen();

//英语支持
//i-文本id c-居中
void Print_EN(byte i);

//菜单界面
// menu screen
uint8_t MenuScreen(uint8_t selected);

//显示APP图标
void DrawApp(int x, byte appID);

//显示APP对应的文本
void DrawAppText(byte appID);
void DrawUIFrame(int x, int y, bool color);
void DrawPoint(int x, int y, bool color);

//FP 密集运算屏保
void DrawIntensiveComputing();

//绘制屏保-密集运算线条
void DrawIntensiveComputingLine();

//模拟数字滚轮 Numerical scrolling effect
void DisplayNum(int Num);

//数值输入界面
// input value screen
uint16_t InputScreen(byte appID);

//设置开机密码
void PasswordSet();
void BootPassword();

//欠压报警设置
// information display screen
void UnderVoltageSet();

//更换烙铁头预设界面
// change tip screen
void ChangeTipScreen();

//温度校准界面
// temperature calibration screen
void CalibrationScreen();

//显示默认烙铁头温度曲线系数
void ShowPTemp(float *p);

//绘制温度曲线
void DrawTempCurve();

//命名界面 文本输入界面
// input tip name screen
void InputNameScreen();

//删除烙铁头
// delete tip screen
void DeleteTipScreen();

//新建烙铁 预设
// add new tip screen
void AddTipScreen();

int InputBigNum(int InputPW, byte appID);
void QRcodeScreen();

//位图缩放 代码片段改自arduboy2
void drawSlowXYBitmapResize(int x, int y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t size, uint8_t color);

//翻转
void Flip(bool Fmode);

//展示版本号
void ShowVersion();

/*进度条
   传入：i=值 a=值的最小值 b=值的最大值 x=左上顶点x轴坐标 y=左上顶点y轴坐标 w=宽度 h=高度 c=颜色
*/
void ProgressBar(int i, int a, int b, byte x, byte y, byte w, byte h, bool c);






#endif