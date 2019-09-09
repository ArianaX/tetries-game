
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include "ELSFK.h"
#define IDI_ICON_MY 102
#define IDB_PNG_HOME 103

//函数声明

BOOL InitWindow(HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



//*******************************************************************

//函数：WinMain()

//功能：Win32应用程序入口函数。创建主窗口，处理消息循环

//*******************************************************************

int PASCAL WinMain(HINSTANCE hInstance, //当前实例句柄
	HINSTANCE hPrevInstance, //前一个实例句柄
	LPSTR lpCmdLine, //命令行字符
	int nCmdShow) //窗口显示方式
{
	MSG msg;
	//创建主窗口
	if (!InitWindow(hInstance, nCmdShow))
		return FALSE;
	//进入消息循环：
	//从该应用程序的消息队列中检取消息，送到消息处理过程，
	//当检取到WM_QUIT消息时，退出消息循环。
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//程序结束
	return msg.wParam;
}

//******************************************************************

//函数：InitWindow()

//功能：创建窗口。

//******************************************************************
static BOOL InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	HWND hwnd; //窗口句柄
	WNDCLASS wc; //窗口类结构

				 //填充窗口类结
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;

	wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON_MY));//修改窗口图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground =(HBRUSH)COLOR_WINDOW;//背景颜色

	wc.lpszMenuName = NULL;
	wc.lpszClassName = "EasyWin";

	//注册窗口类

	RegisterClass(&wc);



	//创建主窗口

	hwnd = CreateWindow(
		"EasyWin", //窗口类名称
		"MY_Sqare", //窗口标题
		WS_SYSMENU |WS_CAPTION |WS_MINIMIZEBOX , //窗口风格，定义为普通型 
		100, //窗口位置的x坐标
		30, //窗口位置的y坐标
		500, //窗口的宽度
		600+40, //窗口的高度
		NULL, //父窗口句柄
		NULL, //菜单句柄
		hInstance, //应用程序实例句柄
		NULL); //窗口创建数据指针

	if (!hwnd) return FALSE;
	//显示并更新窗口
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	return TRUE;
}

//******************************************************************

//函数：WinProc()

//功能：处理主窗口消息

//******************************************************************

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT pt;
	HDC hDC;
	switch (message)
	{
	case WM_CREATE://只创建一次
		//优化初始内容
		index=OnCreate();
		break;
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&pt);

		OnPaint(hDC);

		EndPaint(hWnd, &pt);
		break;
	case WM_KEYDOWN://击键消息
			switch (wParam)
			{
			case VK_RETURN:
				OnReturn(hWnd);
				break;
			case VK_LEFT:
				OnLeft(hWnd);
				break;
			case VK_RIGHT:
				OnRight(hWnd);
				break;
			case VK_SPACE:
				OnChange(hWnd);
				break;
			case VK_DOWN:
				OnDownSpeed(hWnd);
				break;
			case VK_ESCAPE:
				MessageBox(hWnd, "ESC键按下了!", "Keyboard", MB_OK);
				break;
			case VK_UP:
				OnChange(hWnd);
				break;
			}
			break;
	case WM_TIMER:
		OnTimer(hWnd);
		break;
	case WM_RBUTTONDOWN://鼠标消息
		{
			MessageBox(hWnd, "鼠标右键按下了!", "Mouse", MB_OK);
			break;
		}
		case WM_DESTROY://退出消息
			KillTimer(hWnd, DEF_TIME1);
			PostQuitMessage(0);//调用退出函数
			break;
	}
	//调用缺省消息处理过程
	return DefWindowProc(hWnd, message, wParam, lParam);
}
