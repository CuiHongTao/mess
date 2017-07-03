#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
int CharacterChoose (struct state a[])//菜单—物品—消耗品—人物选择 
{
	int i;
	char c;
	printf ("给谁使用？（1~4）\n");
	for (i=0;i<4;i++)
		printf ("%d.%5s\n",i+1,a[i].name);
	for (c=getch();(c<'1'||c>'4');c=getch())
		;
	return (int)c-49;
}
