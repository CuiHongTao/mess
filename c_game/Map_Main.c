/*��ͼģ��������*/
#include<stdio.h>
#include"Map_Head.c"
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
#include <D:\C����������Ϸ\MonsterStruct.c>
void Map_Main(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[])
{	
	void Map_Load(char map[SIZEX][SIZEY]); 
	void Map_Put(char map[SIZEX][SIZEY]);
	void Map_Move(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[]);
	void Map_People_Load(char map[SIZEX][SIZEY]);
	int i;
	//Map_Put(map);//��ͼ�������
	printf ("���������ͼ����q����˵���f����ս��\n");
	Map_Move(map,a,m,e,s,c);//��ͼ�ƶ�������������õ�ͼ��������� 
} 
