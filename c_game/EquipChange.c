#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void EquipChange (struct state a[],struct equip e[],int i,int j)//菜单—装备—装备的更换显示 
{
	void EquipSetup(struct state a[],struct equip e[],int i,int j);
	char command;
	int condition;
	condition=e[i].part;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("◤```````````````````````````````````````````````````````````````◥\n");
	printf ("|%5s    LV：%4d       |力：%3d→",a[j].name,a[j].lv,a[j].strength);
	switch (condition)
		{
			case 0: if (a[j].strength-e[a[j].head].strength+e[i].strength>a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].strength-e[a[j].head].strength+e[i].strength==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].strength-e[a[j].head].strength+e[i].strength);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1: if (a[j].strength-e[a[j].body].strength+e[i].strength>a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].strength-e[a[j].body].strength+e[i].strength==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].strength-e[a[j].body].strength+e[i].strength);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].strength-e[a[j].weapon].strength+e[i].strength>a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].strength-e[a[j].weapon].strength+e[i].strength==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].strength-e[a[j].weapon].strength+e[i].strength);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].strength-e[a[j].leg].strength+e[i].strength>a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].strength-e[a[j].leg].strength+e[i].strength==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].strength-e[a[j].leg].strength+e[i].strength);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].strength-e[a[j].foot].strength+e[i].strength>a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].strength-e[a[j].foot].strength+e[i].strength==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].strength-e[a[j].foot].strength+e[i].strength);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
		}
	printf ("|                           |\n");
	printf ("|EXP ：%5d/%5d       |体：%3d→",a[j].exp,a[j].expmax,a[j].physique);
	switch (condition)
		{
			case 0: if (a[j].physique-e[a[j].head].physique+e[i].physique>a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].physique-e[a[j].head].physique+e[i].physique==a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].physique-e[a[j].head].physique+e[i].physique);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1: if (a[j].physique-e[a[j].body].physique+e[i].physique>a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].physique-e[a[j].body].physique+e[i].physique==a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].physique-e[a[j].body].physique+e[i].physique);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].physique-e[a[j].weapon].physique+e[i].physique>a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].physique-e[a[j].weapon].physique+e[i].physique==a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].physique-e[a[j].weapon].physique+e[i].physique);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].physique-e[a[j].leg].physique+e[i].physique>a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].physique-e[a[j].leg].physique+e[i].physique==a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].physique-e[a[j].leg].physique+e[i].physique);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].physique-e[a[j].foot].physique+e[i].physique>a[j].physique)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].physique-e[a[j].foot].physique+e[i].physique==a[j].strength)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].physique-e[a[j].foot].physique+e[i].physique);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
		}
	printf ("|                           |\n|");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("：%5d/%5d→",a[j].hp,a[j].hpmax);
	switch (condition)
		{
			case 0: if (a[j].hpmax-e[a[j].head].hpmax+e[i].hpmax>a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].hpmax-e[a[j].head].hpmax+e[i].hpmax==a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].hpmax-e[a[j].head].hpmax+e[i].hpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1: if (a[j].hpmax-e[a[j].body].hpmax+e[i].hpmax>a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].hpmax-e[a[j].body].hpmax+e[i].hpmax==a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].hpmax-e[a[j].body].hpmax+e[i].hpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].hpmax-e[a[j].weapon].hpmax+e[i].hpmax>a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].hpmax-e[a[j].weapon].hpmax+e[i].hpmax==a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].hpmax-e[a[j].weapon].hpmax+e[i].hpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].hpmax-e[a[j].leg].hpmax+e[i].hpmax>a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].hpmax-e[a[j].leg].hpmax+e[i].hpmax==a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].hpmax-e[a[j].leg].hpmax+e[i].hpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].hpmax-e[a[j].foot].hpmax+e[i].hpmax>a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].hpmax-e[a[j].foot].hpmax+e[i].hpmax==a[j].hpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].hpmax-e[a[j].foot].hpmax+e[i].hpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
		}
	printf ("|敏：%3d→",a[j].agile);
	switch (condition)
		{
			case 0: if (a[j].agile-e[a[j].head].agile+e[i].agile>a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].agile-e[a[j].head].agile+e[i].agile==a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].agile-e[a[j].head].agile+e[i].agile);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1:if (a[j].agile-e[a[j].body].agile+e[i].agile>a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].agile-e[a[j].body].agile+e[i].agile==a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].agile-e[a[j].body].agile+e[i].agile);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].agile-e[a[j].weapon].agile+e[i].agile>a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].agile-e[a[j].weapon].agile+e[i].agile==a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].agile-e[a[j].weapon].agile+e[i].agile);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].agile-e[a[j].leg].agile+e[i].agile>a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].agile-e[a[j].leg].agile+e[i].agile==a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].agile-e[a[j].leg].agile+e[i].agile);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].agile-e[a[j].foot].agile+e[i].agile>a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].agile-e[a[j].foot].agile+e[i].agile==a[j].agile)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].agile-e[a[j].foot].agile+e[i].agile);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
		}
	printf ("|                           |\n|");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("：%5d/%5d→",a[j].mp,a[j].mpmax);
	switch (condition)
		{
			case 0: if (a[j].mpmax-e[a[j].head].mpmax+e[i].mpmax>a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mpmax-e[a[j].head].mpmax+e[i].mpmax==a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].mpmax-e[a[j].head].mpmax+e[i].mpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1: if (a[j].mpmax-e[a[j].body].mpmax+e[i].mpmax>a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mpmax-e[a[j].body].mpmax+e[i].mpmax==a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].mpmax-e[a[j].body].mpmax+e[i].mpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].mpmax-e[a[j].weapon].mpmax+e[i].mpmax>a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mpmax-e[a[j].weapon].mpmax+e[i].mpmax==a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].mpmax-e[a[j].weapon].mpmax+e[i].mpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].mpmax-e[a[j].leg].mpmax+e[i].mpmax>a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mpmax-e[a[j].leg].mpmax+e[i].mpmax==a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].mpmax-e[a[j].leg].mpmax+e[i].mpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].mpmax-e[a[j].foot].mpmax+e[i].mpmax>a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mpmax-e[a[j].foot].mpmax+e[i].mpmax==a[j].mpmax)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%5d",a[j].mpmax-e[a[j].foot].mpmax+e[i].mpmax);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
		}
	printf ("|智：%3d→",a[j].mentality);
	switch (condition)
		{
			case 0: if (a[j].mentality-e[a[j].head].mentality+e[i].mentality>a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mentality-e[a[j].head].mentality+e[i].mentality==a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].mentality-e[a[j].head].mentality+e[i].mentality);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 1: if (a[j].mentality-e[a[j].body].mentality+e[i].mentality>a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mentality-e[a[j].body].mentality+e[i].mentality==a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].mentality-e[a[j].body].mentality+e[i].mentality);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 2: if (a[j].mentality-e[a[j].weapon].mentality+e[i].mentality>a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mentality-e[a[j].weapon].mentality+e[i].mentality==a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].mentality-e[a[j].weapon].mentality+e[i].mentality);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 3: if (a[j].mentality-e[a[j].leg].mentality+e[i].mentality>a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mentality-e[a[j].leg].mentality+e[i].mentality==a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].mentality-e[a[j].leg].mentality+e[i].mentality);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;
			case 4: if (a[j].mentality-e[a[j].foot].mentality+e[i].mentality>a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
					else if (a[j].mentality-e[a[j].foot].mentality+e[i].mentality==a[j].mentality)SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					else SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
					printf ("%3d",a[j].mentality-e[a[j].foot].mentality+e[i].mentality);
					SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;break;
		}
	printf ("|                           |\n");
	printf ("|-----------------------------------------------------------------|\n");
	EquipInfor(e,i);
	printf ("-------------------------------------------------------------------\n");
	if (e[i].number>0)
		printf ("是否装备？\n1.是\n其他.否\n");
	else
		{
			printf ("装备不存在！\n");
			getch();
			return;
		}
	command=getch();
	if (command=='1')
		EquipSetup(a,e,i,j);
	else
		return;
}
