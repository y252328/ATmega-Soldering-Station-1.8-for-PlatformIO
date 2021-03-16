#ifndef CURVE_FITTING_H
#define CURVE_FITTING_H
#include <Arduino.h>

//********** 曲线拟合程序 **********
//曲线拟合算法来至https://blog.csdn.net/m0_37362454/article/details/82456616 by欧阳小俊

/*==================polyfit(n,x,y,poly_n,a)===================*/
/*=======拟合y=a0+a1*x+a2*x^2+……+apoly_n*x^poly_n========*/
/*=====n是数据个数 xy是数据值 poly_n是多项式的项数======*/
/*===返回a0,a1,a2,……a[poly_n]，系数比项数多一（常数项）=====*/
void polyfit(int n, const int x[], const int y[], int poly_n, float p[]);


/*============================================================
  高斯消元法计算得到 n 次多项式的系数
  n: 系数的个数
  ata: 线性矩阵
  sumxy: 线性方程组的Y值
  p: 返回拟合的结果
  ============================================================*/
void gauss_solve(int n, float A[], float x[], float b[]);

#endif