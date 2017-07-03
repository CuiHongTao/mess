#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include "Map_Head.c"
int Menu (struct state a[],struct consume c[],struct equip e[],struct skill s[],char map[SIZEX][SIZEY])//菜单函数 
{
	void Equip (struct state a[],struct equip e[]);
	void MenuStart (struct state a[]);
	void File (struct state a[],struct consume c[],struct equip e[],struct skill s[],char map[SIZEX][SIZEY]);
	void Goods (struct state a[],struct consume c[],struct equip e[]);
	void Skill (struct state a[],struct skill s[]);
	void Switch (struct state a[],struct equip e[]);
	MenuStart (a);
	char command,i;
	for (command=getch();command!='0';command=getch())
		switch (command)
		{
			case '1':system ("cls");system ("color 07");Goods(a,c,e);system ("cls");MenuStart (a);break;
			case '2':system ("cls");system ("color 07");Equip (a,e);system ("cls");MenuStart (a);break;
			case '3':system ("cls");system ("color 07");Switch (a,e);system ("cls");MenuStart (a);break;
			case '4':system ("cls");system ("color 07");Skill (a,s);system ("cls");MenuStart (a);break;
			case '5':system ("cls");system ("color 07");File (a,c,e,s,map);system ("cls");MenuStart (a);break;
			case '6':system ("cls");system ("color 07");/*设定函数*/system ("cls");MenuStart (a);break;
			case '7':system ("cls");system ("color 07");
				   printf ("是否回到主菜单？\n1.是\n其他.否\n");i=getch();
				   if (i=='1') return 0;
				   system ("cls");system ("color 07");MenuStart (a);break;
			default:; 
		}
	system ("cls");system ("color 07");
	return 1;
}
