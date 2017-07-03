#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
void MenuStart (struct state a[])//菜单界面的显示 
{
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("1.物品      |%5s    LV：%4d  ",a[0].name,a[0].lv);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[0].hp,a[0].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d\n",a[0].mp,a[0].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("2.装备      | EXP：%5d/%5d  力 %3d  体 %3d  敏 %3d  智 %3d\n",
	a[0].exp,a[0].expmax,a[0].strength,a[0].physique,a[0].agile,a[0].mentality);
	printf ("3.属性      |%5s    LV：%4d  ",a[1].name,a[1].lv);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[1].hp,a[1].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d\n",a[1].mp,a[1].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("4.技能      | EXP：%5d/%5d  力 %3d  体 %3d  敏 %3d  智 %3d\n",
	a[1].exp,a[1].expmax,a[1].strength,a[1].physique,a[1].agile,a[1].mentality);
	printf ("5.档案      |%5s    LV：%4d  ",a[2].name,a[2].lv);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[2].hp,a[2].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d\n",a[2].mp,a[2].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("6.设定      | EXP：%5d/%5d  力 %3d  体 %3d  敏 %3d  智 %3d\n",
	a[2].exp,a[2].expmax,a[2].strength,a[2].physique,a[2].agile,a[2].mentality);
	printf ("7.退出      |%5s    LV：%4d  ",a[3].name,a[3].lv);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[3].hp,a[3].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d\n",a[3].mp,a[3].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("0.返回      | EXP：%5d/%5d  力 %3d  体 %3d  敏 %3d  智 %3d\n",
	a[3].exp,a[3].expmax,a[3].strength,a[3].physique,a[3].agile,a[3].mentality);
}
