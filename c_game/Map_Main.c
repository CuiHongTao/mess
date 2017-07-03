/*地图模块主函数*/
#include<stdio.h>
#include"Map_Head.c"
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
void Map_Main(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[])
{	
	void Map_Load(char map[SIZEX][SIZEY]); 
	void Map_Put(char map[SIZEX][SIZEY]);
	void Map_Move(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[]);
	void Map_People_Load(char map[SIZEX][SIZEY]);
	int i;
	//Map_Put(map);//地图输出函数
	printf ("按任意键地图，按q进入菜单，f进入战斗\n");
	Map_Move(map,a,m,e,s,c);//地图移动函数（里面调用地图输出函数） 
} 
