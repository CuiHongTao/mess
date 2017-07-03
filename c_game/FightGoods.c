#include <stdio.h>
#include <conio.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
int FightGoods (struct consume c[])
{
	void GoodsConsumeStart (struct consume c[]);
	int command;
	char command2;
	int i;
	GoodsConsumeStart (c);
	loop:
	command2=getch();
	switch (command2)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':command=command2-48;break;
			default :goto loop;
		}
	printf ("%c",command2);
	command2=getch();
	if (command2>48&&command2<58)
		command=command*10+command2-48;
	if (command<91&&c[command-1].number!=0)
		return command-1;
	else
		{
			printf ("%c 物品不存在！\n",command2);
			goto loop;
		}
}
