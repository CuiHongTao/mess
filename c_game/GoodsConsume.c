#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void GoodsConsume (struct state a[],struct consume c[],struct equip e[])//菜单—物品—消耗品函数 
{
	void ConsumeUse (struct state a[],struct consume c[],int j);
	void GoodsConsumeStart (struct consume c[]);
	void GoodsConsume (struct state a[],struct consume c[],struct equip e[]);
	void GoodsEquip (struct state a[],struct consume c[],struct equip e[]);
	int command;
	char command2;
	int i;
	GoodsConsumeStart (c);
	loop:
	command2=getch();
	if (command2<49||command2>58)
		switch (command2)
			{
				case 'a':system ("cls");system ("color 07");GoodsEquip (a,c,e);return;
				case 'b':system ("cls");system ("color 07");GoodsConsume (a,c,e);return;
				case 'c':system ("cls");system ("color 07");printf ("待健全\n");getch();return;
				case 'd':system ("cls");system ("color 07");printf ("待健全\n");getch();return;
				case '0':return;
				default :goto loop;
			}
	else
		printf ("%c",command2);
	command=command2-48;
	command2=getch();
	if (command2>48&&command2<58)
		command=command*10+command2-48;
	if (command<91)
		{
			system ("cls");
			system ("color 07");
			ConsumeUse(a,c,command-1);
			system ("cls");
			GoodsConsumeStart (c);
		}
	else
		{
			printf ("%c 物品不存在！",command2);
			goto loop;
		}
	goto loop;
}
