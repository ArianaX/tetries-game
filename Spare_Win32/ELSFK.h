#pragma once
#ifndef DEF_ELS_HEAD//��ֹ�ظ�����ͷ�ļ�
#define DEF_ELS_HEAD
#include "resource.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define DEF_TIME1 1234
#define _CRT_SECURE_NO_DEPRECATE
void OnPaint(HDC hdc);
void SetNewTime(HWND hwnd);

int OnCreate();
void OnpaintSqare(HDC hdc, int index);
int CreateRandomSqare();

void CopySqareToBackground();//�������������

void OnReturn(HWND hwnd);

void SqareDown();
void SqareLeft();
void SqareRight();
void ChangeSqare();
void OnChangeLong();
void DestroyOneLine();


void OnTimer(HWND hwnd);
void OnLeft(HWND hwnd);
void OnRight(HWND hwnd);
void OnChange(HWND hwnd);
void OnDownSpeed(HWND hwnd);


//����ͣ������� 0������ 1����
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();
int CanSqareRight();
int CanSqareRight2();
int CanSqareChange();
int CanLineChange();
int CanGameOver();

void Change1To2();
void ShowSqare2(HDC hdc);


#endif // !DEF_ELS_HEAD


