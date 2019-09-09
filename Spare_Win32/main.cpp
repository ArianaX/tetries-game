
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include "ELSFK.h"
#define IDI_ICON_MY 102
#define IDB_PNG_HOME 103

//��������

BOOL InitWindow(HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



//*******************************************************************

//������WinMain()

//���ܣ�Win32Ӧ�ó�����ں��������������ڣ�������Ϣѭ��

//*******************************************************************

int PASCAL WinMain(HINSTANCE hInstance, //��ǰʵ�����
	HINSTANCE hPrevInstance, //ǰһ��ʵ�����
	LPSTR lpCmdLine, //�������ַ�
	int nCmdShow) //������ʾ��ʽ
{
	MSG msg;
	//����������
	if (!InitWindow(hInstance, nCmdShow))
		return FALSE;
	//������Ϣѭ����
	//�Ӹ�Ӧ�ó������Ϣ�����м�ȡ��Ϣ���͵���Ϣ������̣�
	//����ȡ��WM_QUIT��Ϣʱ���˳���Ϣѭ����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//�������
	return msg.wParam;
}

//******************************************************************

//������InitWindow()

//���ܣ��������ڡ�

//******************************************************************
static BOOL InitWindow(HINSTANCE hInstance, int nCmdShow)
{
	HWND hwnd; //���ھ��
	WNDCLASS wc; //������ṹ

				 //��䴰�����
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;

	wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON_MY));//�޸Ĵ���ͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground =(HBRUSH)COLOR_WINDOW;//������ɫ

	wc.lpszMenuName = NULL;
	wc.lpszClassName = "EasyWin";

	//ע�ᴰ����

	RegisterClass(&wc);



	//����������

	hwnd = CreateWindow(
		"EasyWin", //����������
		"MY_Sqare", //���ڱ���
		WS_SYSMENU |WS_CAPTION |WS_MINIMIZEBOX , //���ڷ�񣬶���Ϊ��ͨ�� 
		100, //����λ�õ�x����
		30, //����λ�õ�y����
		500, //���ڵĿ��
		600+40, //���ڵĸ߶�
		NULL, //�����ھ��
		NULL, //�˵����
		hInstance, //Ӧ�ó���ʵ�����
		NULL); //���ڴ�������ָ��

	if (!hwnd) return FALSE;
	//��ʾ�����´���
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	return TRUE;
}

//******************************************************************

//������WinProc()

//���ܣ�������������Ϣ

//******************************************************************

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT pt;
	HDC hDC;
	switch (message)
	{
	case WM_CREATE://ֻ����һ��
		//�Ż���ʼ����
		index=OnCreate();
		break;
	case WM_PAINT:
		hDC=BeginPaint(hWnd,&pt);

		OnPaint(hDC);

		EndPaint(hWnd, &pt);
		break;
	case WM_KEYDOWN://������Ϣ
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
				MessageBox(hWnd, "ESC��������!", "Keyboard", MB_OK);
				break;
			case VK_UP:
				OnChange(hWnd);
				break;
			}
			break;
	case WM_TIMER:
		OnTimer(hWnd);
		break;
	case WM_RBUTTONDOWN://�����Ϣ
		{
			MessageBox(hWnd, "����Ҽ�������!", "Mouse", MB_OK);
			break;
		}
		case WM_DESTROY://�˳���Ϣ
			KillTimer(hWnd, DEF_TIME1);
			PostQuitMessage(0);//�����˳�����
			break;
	}
	//����ȱʡ��Ϣ�������
	return DefWindowProc(hWnd, message, wParam, lParam);
}
