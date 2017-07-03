#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void Equip (struct state a[],struct equip e[])//菜单—装备函数 
{
	void EquipStart (struct state a[],struct equip e[],int j);
	void EquipChange (struct state a[],struct equip e[],int i,int j);
	int command,j;
	char command2;
	printf ("请选择角色！\na.%5s\nb.%5s\nc.%5s\nd.%5s\n",a[0].name,a[1].name,a[2].name,a[3].name);
	loop2:
	command2=getch ();
	switch (command2)
		{
			case 'a':j=0;break;
			case 'b':j=1;break;
			case 'c':j=2;break;
			case 'd':j=3;break;
			default :goto loop2;break;
		}
	system ("cls");
	EquipStart(a,e,j);
	loop:
	command2=getch();
	
	if (command2>'0'&&command2<='9')
		{
			command=command2-48;
			printf ("%c",command2);
		}
	else if (command2=='0')
		return;
	else
		goto loop;
	command2=getch();
	if (command2>'0'&&command2<='9')
		command=command*10+command2-48;
	if (command<91)
		{
			system ("cls");
			system ("color 07");
			EquipChange(a,e,command-1,j);
			system ("cls");
			EquipStart (a,e,j);
		}
	else
		{
			printf ("%c 装备不存在！",command2);
			goto loop;
		}
	goto loop;
}
