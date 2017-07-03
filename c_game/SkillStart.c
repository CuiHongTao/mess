#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
void SkillStart (struct state a[])//菜单—技能界面的显示 
{
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤<><><><><><><><><><><><><><><><*><><><><><><><><><><><><><><><>◥\n");
	printf ("|   a.%5s      |                                                |\n",a[0].name);
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|----------------|                                                |\n");
	printf ("|   b.%5s      |                                                |\n",a[1].name);
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|----------------|                                                |\n");
	printf ("|   c.%5s      |                                                |\n",a[2].name);
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|----------------|                                                |\n");
	printf ("|   d.%5s      |                                                |\n",a[3].name);
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|                |                                                |\n");
	printf ("|================|                                                |\n");
	printf ("|////////////////////////////0. 返 回\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|\n");
}
