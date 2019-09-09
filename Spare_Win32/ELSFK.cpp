#include "ELSFK.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS

char g_arrBackGround[20][10] = { 0 };//背景数组
char g_arrSqare[2][4] = { 0 };//随机图形

int g_x = -2;
int g_y = -1;

int g_score = 0;

int time_start = 1000;//初始级别；
void OnPaint(HDC hdc)
{
	char StrScore[80] = {0};//一分160
	//创建兼容性DC
	HDC HMEMdc = CreateCompatibleDC(hdc);//只是一个编号
	//创建一张纸
	HBITMAP hbitmap = CreateCompatibleBitmap(hdc, 500, 600);
	SelectObject(HMEMdc, hbitmap);
	
	
	OnpaintSqare(HMEMdc, index);
	ShowSqare2(HMEMdc);

	//Rectangle(HMEMdc, 350, 50, 450, 150);//预测框

	//内存DC传到表面上
	BitBlt(hdc,0,0,300,600,HMEMdc,0,0,SRCCOPY );//只画左侧游戏区

	//itoa(g_score, StrScore, 10);
	int length = sprintf(StrScore, "%d", g_score);
	TextOut(hdc,400,400, StrScore,length);

	DeleteObject(hbitmap);
	DeleteDC(HMEMdc);
}

void SetNewTime(HWND hwnd)
{
	//打开定时器
	time_start = 10;
	SetTimer(hwnd, DEF_TIME1, time_start, NULL);
}

int  OnCreate()
{
	int index;
	srand((unsigned int)time(NULL));//种子
	index =CreateRandomSqare();
	CopySqareToBackground();
	return index;
}

void OnpaintSqare(HDC hdc,int index)
{
	Rectangle(hdc, 0, 0, 300, 600);
	
	HBRUSH hOldBrush;
	HBRUSH hNewBrush ;

	switch (index)
	{
	case 0://Z
		hNewBrush = CreateSolidBrush(RGB(220, 203, 190));//橘红
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 1://Z反
		hNewBrush = CreateSolidBrush(RGB(250, 248, 3));//黄
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 2://--|
		hNewBrush = CreateSolidBrush(RGB(3, 118, 250));//蓝色
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 3://|--
		hNewBrush = CreateSolidBrush(RGB(253, 5, 222));//紫红色
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 4://-|-
		hNewBrush = CreateSolidBrush(RGB(253, 5, 15));//红色
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 5://田
		hNewBrush = CreateSolidBrush(RGB(10, 253, 5));//绿色
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	case 6://----
		hNewBrush = CreateSolidBrush(RGB(5, 253, 246));//qingse
		hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (1 == g_arrBackGround[i][j])
				{
					Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
				}
			}
		}
		hNewBrush = (HBRUSH)SelectObject(hdc, hOldBrush);
		DeleteObject(hNewBrush);
		break;
	}	
}

int CreateRandomSqare()
{
	
	index=rand()%7;
	switch (index)
	{
	case 0://Z
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 0, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;
		g_x = 0;
		g_y = 3;
		break;
	case 1://Z反
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;
		g_x = 0;
		g_y = 3;
		break;
	case 2://--|
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 1, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;
		g_x = 0;
		g_y = 3;
		break;
	case 3://|--
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;
		g_x = 0;
		g_y = 3;
		break;
	case 4://-|-
		g_arrSqare[0][0] =0, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 0;
		g_x = 0;
		g_y = 3;
		break;
	case 5://田
		g_arrSqare[0][0] = 1, g_arrSqare[0][1] = 1, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 0, g_arrSqare[1][3] = 0;
		break;
	case 6://----
		g_arrSqare[0][0] = 0, g_arrSqare[0][1] = 0, g_arrSqare[0][2] = 0, g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1, g_arrSqare[1][1] = 1, g_arrSqare[1][2] = 1, g_arrSqare[1][3] = 1;
		g_x = 1;
		g_y = 4;
		break;

	}
	return index;
}

void CopySqareToBackground()
{
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			g_arrBackGround[i][j + 3] = g_arrSqare[i][j];
		}
	}
}

void OnReturn(HWND hwnd)
{
	//打开定时器
	time_start = 1000;
	SetTimer(hwnd, DEF_TIME1, time_start, NULL);
}

void SqareDown()
{
	for (int i = 19; i >=0; i--)
	{
		for (int  j = 0; j < 10; j++)
		{
			if (1==g_arrBackGround[i][j])
			{
				g_arrBackGround[i + 1][j] = 1;
				g_arrBackGround[i][j] = 0;
			}

		}
	}
}

void SqareLeft()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j - 1] = 1;
				g_arrBackGround[i][j] = 0;
			}
		}
	}

}

void SqareRight()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 9; j>=0; j--)
		{
			if (1 == g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j + 1] = 1;
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

void ChangeSqare()
{
	char arrSqare[3][3] = { 0 };
	if (1 == CanSqareChange())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int  j = 0; j < 3; j++)
			{
				arrSqare[i][j] = g_arrBackGround[g_x + i][g_y + j];
			}
		}
		//开始变换~~
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				g_arrBackGround[g_x + i][g_y + j] =arrSqare[2-j][i];
			}
		}
	}	
}

void OnTimer(HWND hwnd)
{
	HDC hdc=GetDC(hwnd);
	if (1==CanSqareDown()&& CanSqareDown2()==1)
	{
		SqareDown();
		g_x++;
	}
	else
	{
		//1 to2
		Change1To2();
		
		DestroyOneLine();

		if (0 == CanGameOver())
		{
			KillTimer(hwnd, DEF_TIME1);
			return;
		}
		else
		{
			index = CreateRandomSqare();
			CopySqareToBackground();
			//打开定时器
			time_start = 1000;
			SetTimer(hwnd, DEF_TIME1, time_start, NULL);
		}
		
	}

	//OnpaintSpare(hdc);
	//兼容性dc
	OnPaint(hdc);
	ReleaseDC(hwnd, hdc);
}

void OnLeft(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	if (CanSqareLeft() == 1 && 1 == CanSqareLeft2())//
	{
		SqareLeft();
		g_y--;
		OnPaint(hdc);
	}
	OnPaint(hdc);
	ReleaseDC(hwnd,hdc);

}

void OnRight(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	if (CanSqareRight() == 1&&1==CanSqareRight2())
	{
		SqareRight();
		g_y++;
		OnPaint(hdc);
	}

	ReleaseDC(hwnd, hdc);
}

void OnChange(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	//if (1 == CanSqareChange())
	{
		switch (index)
		{
		case 0://Z
		case 1://Z反
		case 2://--|
		case 3://|--
		case 4://-|-
			ChangeSqare();
			break;
		case 5://田
			break;
		case 6://----
			if (CanLineChange() == 1)
			{
				OnChangeLong();
			}
				
			break;
		}
	}
	
	OnPaint(hdc);
	ReleaseDC(hwnd,hdc);
}

void OnDownSpeed(HWND hwnd)
{
	//打开定时器
	time_start = 10;
	SetTimer(hwnd, DEF_TIME1, time_start, NULL); 
}

void OnChangeLong()
{
	if (g_arrBackGround[g_x][g_y-1]==1)//横着的
	{
		g_arrBackGround[g_x][g_y - 1] = 0;
		g_arrBackGround[g_x][g_y + 1] = 0;
		g_arrBackGround[g_x][g_y + 2] = 0;

		if (2==g_arrBackGround[g_x+1][g_y])
		{
			g_arrBackGround[g_x -3][g_y] = 1;
			g_arrBackGround[g_x - 1][g_y] = 1;
			g_arrBackGround[g_x - 2][g_y] = 1;
			g_x = g_x - 2;
		}
		else if(2 == g_arrBackGround[g_x+2][g_y])
		{
			g_arrBackGround[g_x +1][g_y] = 1;
			g_arrBackGround[g_x - 1][g_y] = 1;
			g_arrBackGround[g_x - 2][g_y] = 1;
			g_x = g_x - 1;
		}
		else
		{
			g_arrBackGround[g_x + 1][g_y] = 1;
			g_arrBackGround[g_x - 1][g_y] = 1;
			g_arrBackGround[g_x +2][g_y] = 1;
		}

	}
	else
	{
		g_arrBackGround[g_x + 1][g_y] = 0;
		g_arrBackGround[g_x - 1][g_y] = 0;
		g_arrBackGround[g_x + 2][g_y] = 0;
		if (2 == g_arrBackGround[g_x][g_y + 1] || g_y == 9)
		{
			g_arrBackGround[g_x][g_y -3] = 1;
			g_arrBackGround[g_x][g_y - 1] = 1;
			g_arrBackGround[g_x][g_y - 2] = 1;
			g_y = g_y - 2;
		}
		else if (2 == g_arrBackGround[g_x][g_y + 2]|| g_y == 8)
		{
			g_arrBackGround[g_x][g_y + 1] = 1;
			g_arrBackGround[g_x][g_y -1] = 1;
			g_arrBackGround[g_x][g_y -2] = 1;
			g_y = g_y - 1;
		}
		else if(2 == g_arrBackGround[g_x][g_y - 1]||g_y==0)
		{
			g_arrBackGround[g_x][g_y+1] = 1;
			g_arrBackGround[g_x][g_y+2] = 1;
			g_arrBackGround[g_x][g_y+3] = 1;
			g_y = g_y +1;
		}

		else
		{
			
			g_arrBackGround[g_x][g_y - 1] = 1;
			g_arrBackGround[g_x][g_y + 1] = 1;
			g_arrBackGround[g_x][g_y + 2] = 1;
		}
		
	}
}

void DestroyOneLine()
{
	int sum = 0;
	for (int i = 19; i >=0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			sum = sum + g_arrBackGround[i][j];
		}
		if (sum == 20)
		{
			for (int s = i; s > 2; s--)
			{
				for (int k = 0; k < 10; k++)
				{
					g_arrBackGround[s][k] = g_arrBackGround[s - 1][k];
					g_score++;
				}
			}
			i = i+1;
		}
		sum = 0;
	}
	

}

int CanSqareDown()
{
	for (int i = 0; i < 10; i++)
	{
		if (1 == g_arrBackGround[19][i])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareDown2()
{
	for (int i = 19; i >=0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i + 1][j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int CanSqareLeft()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == g_arrBackGround[i][0])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareLeft2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j	= 0; j < 10; j++)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i][j - 1])
				{
					return 0;
				}
			}
			
		}
	}
	return 1;
}

int CanSqareRight()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == g_arrBackGround[i][9])
		{
			return 0;
		}
	}
	return 1;
}

int CanSqareRight2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 9; j >=0; j--)
		{
			if (1 == g_arrBackGround[i][j])
			{
				if (2 == g_arrBackGround[i][j + 1])
				{
					return 0;
				}
			}
			
		}
	}
	return 1;
}

int CanSqareChange()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (2 == g_arrBackGround[g_x + i][g_y + j])
			{
				return 0;
			}
		}
	}
	if (g_y < 0)
	{
		g_y = 0;
	}
	else if (g_y + 2>9)
	{
		g_y = 7;
	}

	return 1;
}

int CanLineChange()
{
	int i;
	int j;
	for (i = 1; i < 4; i++)
	{
		if (2==g_arrBackGround[g_x][g_y+i]|| g_y + i>9)
		{
			break;
		}
	}
	for (j = 1; j < 4; j++)
	{
		if (2 == g_arrBackGround[g_x][g_y -j] || g_y - j<0)
		{
			break;
		}
	}
	if ((i-1+j-1)<3)
	{
		return 0;
	}
	return 1;
}

int CanGameOver()
{
	for(int i=0;i<10;i++)
	{
		if (g_arrBackGround[0][i] == 2)
		{
			MessageBox(NULL, "GameOver", "提示", MB_OK);
			return 0;
		}
	}
	return 1;
}


void Change1To2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1==g_arrBackGround[i][j])
			{
				g_arrBackGround[i][j] = 2;
			}
		}
	}
}

void ShowSqare2(HDC hdc)
{
	//Rectangle(hdc, 0, 0, 300, 600);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush = CreateSolidBrush(RGB(190, 193, 220));
	hOldBrush =(HBRUSH) SelectObject(hdc, hNewBrush);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (2 == g_arrBackGround[i][j])
			{
				Rectangle(hdc, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}
	hNewBrush =(HBRUSH) SelectObject(hdc, hOldBrush);
	DeleteObject(hNewBrush);
}
