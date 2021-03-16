#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <EEPROM.h>
#include <PID_v1.h>
#include <Arduboy2.h>

// Firmware version
#define VERSION       "v1.8t8+0"

#define EN_CHINESE false
#define EN_JAPANESE false

#define EN_EEPROM false

// Type of rotary encoder
#define ROTARY_TYPE   0         // 0: 2 increments/step; 1: 4 increments/step

// Pins
#define SENSOR_PIN    A0        // temperature sense
#define VIN_PIN       A6        // input voltage sense
#define BUZZER_PIN     5        // buzzer
#define BUTTON_PIN     6        // rotary encoder switch
#define ROTARY_1_PIN   7        // rotary encoder 1
#define ROTARY_2_PIN   8        // rotary encoder 2
#define CONTROL_PIN    9        // heater MOSFET PWM control
#define SWITCH_PIN    10        // handle vibration switch

// Default temperature control values (recommended soldering temperature: 300-380°C)
#define TEMP_MIN      150       // min selectable temperature
#define TEMP_MAX      450       // max selectable temperature
#define TEMP_DEFAULT  320       // default start setpoint
#define TEMP_SLEEP    150       // temperature in sleep mode
#define TEMP_BOOST     60       // temperature increase in boost mode
#define TEMP_STEP      5       // rotary encoder temp change steps

// Default tip temperature calibration values
#define TEMPCHP       30        // chip temperature while calibration
#define TIPMAX        30         // max number of tips
#define TIPNAMELENGTH 7         // max length of tip names (including termination)
#define TIPNAME       "SZtip"   // default tip name


// Default timer values (0 = disabled)
#define TIME2SLEEP     5        // time to enter sleep mode in minutes
#define TIME2OFF      15        // time to shut off heater in minutes
#define TIMEOFBOOST   40        // time to stay in boost mode in seconds

// Control values
#define TIME2SETTLE   300       // time in microseconds to allow OpAmp output to settle
#define SMOOTHIE      0.05      // OpAmp output smooth factor (1=no smoothing; 0.05 default)
#define PID_ENABLE    true      // enable PID control
#define BEEP_ENABLE   true      // enable/disable buzzer
#define MAINSCREEN    1         // type of main screen (0: big numbers; 1: more infos)

// EEPROM identifier
#define EEPROM_IDENT   0x140C   // to identify if EEPROM was written by this program

//蜂鸣器 beep
#define SetBeepCoolTime 200
// unsigned long BeepCoolTime; ??
#define CutOffPowerAlarm true
#define TemperatureArrivalReminder true

// Curve fitting
#define TempP1 10.2675914764
#define TempP2 1.7323191166
#define TempP3 -0.0033245713
#define TempP4 0.0000045338


// ==========================================
// =       Global Variable Declaration      =
// ==========================================

extern Arduboy2 arduboy;
extern bool lastbutton;

// Define the aggressive and conservative PID tuning parameters
extern double aggKp, aggKi, aggKd;
extern double consKp, consKi, consKd;

// Default values that can be changed by the user and stored in the EEPROM
extern uint16_t  DefaultTemp;
extern uint16_t  SleepTemp  ;
extern uint8_t   BoostTemp  ;
extern uint8_t   Time2sleep ;
extern uint8_t   Time2off   ; 
extern uint8_t   TimeOfBoost;
extern uint8_t   MainScrType;
extern bool      PIDenable  ;
extern bool      BeepEnable ;

//温度拟合
extern float    PTemp[4]; //温度拟合系数
extern const uint16_t CalTemp[9];
extern char      TipName[TIPNAMELENGTH];
extern uint8_t   CurrentTip;
extern uint8_t   NumberOfTips;

//中断引脚相关变量
extern volatile uint8_t  a0, b0, c0, d0;
extern volatile bool     ab0;
extern volatile int      Count, CountMin, CountMax, CountStep;
extern volatile bool     handleMoved;

//温度控制相关变量
extern uint16_t  SetTemp, ShowTemp, gap, Step;
extern double    Input, Output, Setpoint, RawTemp, CurrentTemp, ChipTemp;

//电压读取相关变量
extern uint16_t  Vcc, Vin;

// State variables
extern bool      InSleepMode;
extern bool      InOffMode  ;
extern bool      InBoostMode;
extern bool      InCalibMode;
extern bool      IsWorky    ;
extern bool      BeepIfWorky;
extern bool      TipIsPresent;
extern bool      FlipState;
// Timing variables
extern uint32_t  Sleepmillis;
extern uint32_t  Boostmillis;
extern uint32_t  Buttonmillis;
extern uint8_t   GoneMinutes;
extern uint8_t   GoneSeconds;
extern uint8_t   SensorCounter;
//串口助手
//int x, y, a, b;

//欠压报警
extern byte UnderVoltage;

//MOS管控制延迟
extern uint16_t  Time2settle;

//模拟数字滚轮 Numerical scrolling effect
extern int Value;
extern int LastValue[3];
extern int SlidingAnimationY[3];

//开机密码 BootPassword
extern int Password;

//屏幕保护-主题：密集运算
extern byte Line[4];

//编码器旋转调整方向设定
extern bool RotaryD;

//开机非线性动画
extern byte BootAnimationY;

//初始化PID参数
extern PID ctrl;

//NMOS - PMOS模式切换
#define UsePMOS false

//LANG 语言支持
/*  0 - 中文 CHINESE
    1 - 英文 ENGLISH
    2 - 日语 x (此版本不支持)
*/
extern byte LANG;
#endif