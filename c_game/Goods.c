#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
void Goods (struct state a[],struct consume c[],struct equip e[])//�˵�����Ʒ���� 
{
	void GoodsConsume (struct state a[],struct consume c[],struct equip e[]);
	void GoodsEquip (struct state a[],struct consume c[],struct equip e[]);
	void GoodsStart ();
	char command;
	int i;
	GoodsStart ();
	loop:
	command=getch();
	switch (command)
		{
			case 'a':system ("cls");system ("color 07");GoodsEquip (a,c,e);break;
			case 'b':system ("cls");system ("color 07");GoodsConsume (a,c,e);break;
			case 'c':system ("cls");system ("color 07");printf ("����ȫ\n");getch();break;
			case 'd':system ("cls");system ("color 07");printf ("����ȫ\n");getch();break;
			case '0':return;
			default :goto loop;
		}
}
