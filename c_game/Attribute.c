#include <stdio.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
void Attribute(struct state a[],struct equip e[],int i)//�˵������Ե���ʾ 
{
	printf(" |============================������============================| ");
	printf(" |                   |                                              | ");
	printf(" |  ��������� |  ��ɫ��:%5s      LV:%3d      EXP:%3d/%3d   | ",a[i].name,a[i].lv,a[i].exp,a[i].expmax);
	printf(" |  ��            �� |  Ѫ��:%3d/%3d       ��������:%3d             | ",a[i].hp,a[i].hpmax,a[i].crit);
	printf(" |  ��            �� |  ����:%3d/%3d       ��������:%3d             | ",a[i].mp,a[i].mpmax,a[i].dodge);
	printf(" |  ��   ��ͷ��   �� |  ����:%3d           ħ������:                | ",a[i].strength);
	printf(" |  ��            �� |  ����:%3d           ħ���˺�:                | ",a[i].physique);
	printf(" |  ��            �� |  ����:%3d           �������:                | ",a[i].agile);
	printf(" |  ��������� |  ����:%3d           �����˺�:                | ",a[i].mentality);
	printf(" |                   |                                              | ");
	printf(" |============================������============================| ");
	printf(" |                                                                  | ");
	printf(" |���Ѵ���װ����                                                    | "); 
	printf(" |    ������%7s                                                 | ",e[a[i].weapon].name); 
	printf(" |    ���ɣ�%7s                  ͷ����%7s                  | ",e[a[i].body].name,e[a[i].head].name); 
	printf(" |    ���ȣ�%7s                  Ь�ӣ�%7s                  | ",e[a[i].leg].name,e[a[i].foot].name);
	printf(" |============================������============================| ");
	printf(" |���ɫ�����飺                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |                                                                  | ");
	printf(" |============================������============================| ");
	printf(" |             ����1:�鿴��Ľ�ɫ;����2,3,4:�鿴���ͬ�顣          | ");
	printf(" |               ����w,s�����л���ɫ;����0:�������˵���             | ");
	printf(" |============================������============================| ");
}
