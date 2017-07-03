#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
void SkillStart2 (struct state a[],struct skill s[],int i)//菜单—技能二级界面的显示 
{
	int j;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤<><><><><><><><><><><><><><><><*><><><><><><><><><><><><><><><>◥\n");
	for (j=0;j<20;)
		{
			printf ("|   ");
			if (i==j/5)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					printf ("%c.%5s",j/5+97,a[j/5].name);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				printf ("%c.%5s",j/5+97,a[j/5].name);
			printf ("      |");
			if (s[a[i].skill[j]].type==0)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_BLUE);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_GREEN);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			printf ("|\n");
			printf ("|                |");
			if (s[a[i].skill[j]].type==0)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_BLUE);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_GREEN);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			printf ("|\n");
			printf ("|                |");
			if (s[a[i].skill[j]].type==0)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_BLUE);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_GREEN);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			printf ("|\n");
			printf ("|                |");
			if (s[a[i].skill[j]].type==0)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_BLUE);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_GREEN);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			printf ("|\n");
			printf ("|----------------|");
			if (s[a[i].skill[j]].type==0)
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_BLUE);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			else
				{
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED|FOREGROUND_GREEN);
					printf ("%2d.%5s  %38s",j+1,s[a[i].skill[j]].name,s[a[i].skill[j]].infor);j++;
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
			printf ("|\n");
		}
	printf ("|////////////////////////////0. 返 回\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|\n");
}
