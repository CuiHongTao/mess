#include <stdio.h>
#include <stdlib.h>
#include <D:\C语言文字游戏\EquipStruct.c>
void EquipInfor (struct equip e[],int j)//菜单—装备—装备信息的显示 
{
	if (e[j].flag==1)
		printf ("%s\n",e[j].infor);
	else
		printf ("未持有过该装备。\n");
}
