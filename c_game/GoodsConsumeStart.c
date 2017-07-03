#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\ConsumeStruct.c>
void GoodsConsumeStart (struct consume c[])//菜单—物品—消耗品界面的显示 
{
	int i,j,k=0;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤```````````````````````````````````````````````````````````````◥\n");
	printf ("||    a.装备     |    ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("b.消耗品");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("   |    c.材料     |    d.贵重品   ||\n");
	printf ("|-----------------------------------------------------------------|\n");
	printf ("|");
	for (i=0;i<90;i++)
		if (c[i].flag==1)
			{
				if (c[i].number==0)
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
						printf ("%2d.",i+1);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
						printf ("%5s×%2d ",c[i].name,c[i].number);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					}
				else
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
						printf ("%2d.",i+1);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
						printf ("%5s×%2d ",c[i].name,c[i].number);
					}
					k++;
				if (k%5==0)
					printf ("|\n|");
			}
	while (k<90)
		{
			printf ("             ");
			k++;
			if(k%5==0)
				printf ("|\n|");
		}
	printf ("============================0. 返 回=============================|\n");
}
