/*进入下一个地图的函数，各个地图的关系也在这里*/
#include<stdio.h>
#include"Map_Head.c"

void Map_NextGoto(char map[SIZEX][SIZEY],int x,int y)
{
	
	switch(map_people_mark)
	{
		case 1:map_up=2;map_down=4;map_right=3;map_left=5;break;
		case 2:map_up=6;map_down=1;break;
		default:;break;
	}
}
