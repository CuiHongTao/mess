#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void GoodsEquip (struct state a[],struct consume c[],struct equip e[])//菜单—物品—装备函数 
{
	void EquipInfor (struct equip e[],int j);
	void GoodsEquipStart (struct equip e[]);
	void GoodsConsume (struct state a[],struct consume c[],struct equip e[]);
	void GoodsEquip (struct state a[],struct consume c[],struct equip e[]);
	int command;
	char command2;
	int i;
	GoodsEquipStart (e);
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
	if (command<90)
		{
			system ("cls");
			system ("color 07");
			EquipInfor(e,command-1);
			getch();
			system ("cls");
			GoodsEquipStart (e);
		}
	else
		{
			printf ("%c 装备不存在！",command2);
			goto loop;
		}
	goto loop;
}
