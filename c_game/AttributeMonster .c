#include <stdio.h>
#include <windows.h>
#include <D:\C����������Ϸ\MonsterStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
void AttributeMonster (struct monster m[],struct skill s[],int i)//�˵������Ե���ʾ 
{
	printf(" |============================����������============================| "); 
	printf(" |                                                                  | ");
	printf(" |         ������:%5s                 LV:%3d                      | ",m[i].name,m[i].lv);
	printf(" |         Ѫ��:%3d/%3d               �ɻ��EXP:%3d                 | ",m[i].hp,m[i].hpmax,m[i].exp);
	printf(" |         ����:%3d/%3d               ��������:%3d                  | ",m[i].mp,m[i].mpmax,m[i].crit);
	printf(" |         ����:%3d                   ��������:%3d                  | ",m[i].strength,m[i].dodge);
	printf(" |         ����:%3d                   ���ܼ���:%3d                  | ",m[i].physique,m[i].flee);
	printf(" |         ����:%3d                   �����޶�:%3d                  | ",m[i].agile,m[i].area);
	printf(" |         ����:%3d                                                 | ",m[i].mentality);
	printf(" |============================����������============================| ");
	printf(" |����＼�ܣ�                                                      | ");  
	printf(" |   1:%5s     2:%5s     3:%5s     4:%5s     5:%5s        | ",s[m[i].skill[0]].name,s[m[i].skill[1]].name,s[m[i].skill[2]].name,s[m[i].skill[3]].name,s[m[i].skill[4]].name);
	printf(" |   6:%5s     7:%5s     8:%5s     9:%5s    10:%5s        | ",s[m[i].skill[5]].name,s[m[i].skill[6]].name,s[m[i].skill[7]].name,s[m[i].skill[8]].name,s[m[i].skill[9]].name);
	printf(" |  11:%5s    12:%5s    13:%5s    14:%5s    15:%5s        | ",s[m[i].skill[10]].name,s[m[i].skill[11]].name,s[m[i].skill[12]].name,s[m[i].skill[13]].name,s[m[i].skill[14]].name);
	printf(" |  16:%5s    17:%5s    18:%5s    19:%5s    20:%5s        | ",s[m[i].skill[15]].name,s[m[i].skill[16]].name,s[m[i].skill[17]].name,s[m[i].skill[18]].name,s[m[i].skill[19]].name);
	printf(" |============================����������============================| ");
	printf(" |������飺                                                      | ");
	printf(" |     %-61s| ",m[i].infor);
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |============================����������============================| ");
	printf(" |                                                                  | ");
	printf(" |============================����������============================| ");
}
