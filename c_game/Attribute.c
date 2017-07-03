#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void Attribute(struct state a[],struct equip e[],int i)//菜单—属性的显示 
{
	printf(" |============================◇◇◇◇◇============================| ");
	printf(" |                   |                                              | ");
	printf(" |  ☆☆☆☆☆☆☆☆ |  角色名:%5s      LV:%3d      EXP:%3d/%3d   | ",a[i].name,a[i].lv,a[i].exp,a[i].expmax);
	printf(" |  ☆            ☆ |  血量:%3d/%3d       基础暴击:%3d             | ",a[i].hp,a[i].hpmax,a[i].crit);
	printf(" |  ☆            ☆ |  蓝量:%3d/%3d       基础闪避:%3d             | ",a[i].mp,a[i].mpmax,a[i].dodge);
	printf(" |  ☆   ◎头像   ☆ |  力量:%3d           魔法防御:                | ",a[i].strength);
	printf(" |  ☆            ☆ |  体力:%3d           魔法伤害:                | ",a[i].physique);
	printf(" |  ☆            ☆ |  敏捷:%3d           物理防御:                | ",a[i].agile);
	printf(" |  ☆☆☆☆☆☆☆☆ |  智力:%3d           物理伤害:                | ",a[i].mentality);
	printf(" |                   |                                              | ");
	printf(" |============================◇◇◇◇◇============================| ");
	printf(" |                                                                  | ");
	printf(" |◎已穿上装备：                                                    | "); 
	printf(" |    武器：%7s                                                 | ",e[a[i].weapon].name); 
	printf(" |    躯干：%7s                  头盔：%7s                  | ",e[a[i].body].name,e[a[i].head].name); 
	printf(" |    护腿：%7s                  鞋子：%7s                  | ",e[a[i].leg].name,e[a[i].foot].name);
	printf(" |============================◇◇◇◇◇============================| ");
	printf(" |◎角色人物简介：                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |============================◇◇◇◇◇============================| ");
	printf(" |             输入1:查看你的角色;输入2,3,4:查看你的同伴。          | ");
	printf(" |               输入w,s上下切换角色;输入0:返回主菜单。             | ");
	printf(" |============================◇◇◇◇◇============================| ");
}
