#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
void ConsumeUse (struct state a[],struct consume c[],int j)//菜单—物品—消耗品的使用 
{
	int CharacterChoose (struct state a[]);
	void ConsumeInfor (struct consume c[],int j);
	int i;
	char flag;
	if (c[j].number<1)
		{
			printf ("物品不存在!\n");
			getch();
			return;
		}
	ConsumeInfor (c,j);
	i=CharacterChoose (a);
	printf ("是否使用物品%5s？\n1.是\n其他.否\n",c[j].name);
	flag=getch ();
	if (flag=='1')
		{
			a[i].lv+=c[j].lv;
			a[i].exp+=c[j].exp;
			a[i].hp+=c[j].hp;
			a[i].hpmax+=c[j].hpmax;
			if (a[i].hp>a[i].hpmax)
				{
					a[i].hp=a[i].hpmax;
					printf ("血量已达到最大值\n");
					getch();
				}
			a[i].mp+=c[j].mp;
			a[i].mpmax+=c[j].mpmax;
			if (a[i].mp>a[i].mpmax)
				{
					a[i].mp=a[i].mpmax;
					printf ("蓝量已达到最大值\n");
					getch();
				}
			a[i].strength+=c[j].strength;
			a[i].physique+=c[j].physique;
			a[i].agile+=c[j].agile;
			a[i].mentality+=c[j].mentality;
			c[j].number--;
		}
	else
		return;
}
