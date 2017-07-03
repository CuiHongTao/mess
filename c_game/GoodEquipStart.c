#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\EquipStruct.c>
void GoodsEquipStart (struct equip e[])
{
	int i,j,k=0;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤```````````````````````````````````````````````````````````````◥\n");
	printf ("||    ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("a.装备");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("     |    b.消耗品   |    c.材料     |    d.贵重品   ||\n");
	printf ("|-----------------------------------------------------------------|\n");
	printf ("|");
	for (i=0;i<90;i++)
		if (e[i].flag==1)
			{
				if (e[i].number==0)
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
						printf ("%2d.%5s*%2d  ",i+1,e[i].name,e[i].number);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					}
				else
					printf ("%2d.%5s*%2d  ",i+1,e[i].name,e[i].number);
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
