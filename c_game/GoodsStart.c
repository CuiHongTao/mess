#include <stdio.h>
#include <windows.h>
void GoodsStart ()//菜单—物品界面的显示 
{
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤```````````````````````````````````````````````````````````````◥\n");
	printf ("||    a.装备     |    b.消耗品   |    c.材料     |    d.贵重品   ||\n");
	printf ("|-----------------------------------------------------------------|\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|                                                                 |\n");
	printf ("|============================0. 返 回=============================|\n");
}
