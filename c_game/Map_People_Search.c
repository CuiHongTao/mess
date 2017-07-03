/*地图人物位置查找函数*/
#include<stdio.h>
#include"Map_Head.c"

void Map_People_Search(char map[SIZEX][SIZEY])
{
	int i,j;
	
	for(i=0;i<SIZEX;i++)								//用于查找人物的坐标 
	{
		for(j=0;j<SIZEY;j++,j++)
		{
			if((map[i][j]==-95)&&(map[i][j+1]==-30))
			{
				map_people_x=i;
				map_people_y=j;
				
				if (map_people_y+34>=SIZEY)
					map_put_right=SIZEY;
				else
					map_put_right=map_people_y+34;
				if (map_people_y-34<=0)
					map_put_left=0;
				else
					map_put_left=map_people_y-34;
				if (map_people_x-12<=0)
					map_put_up=0;
				else
					map_put_up=map_people_x-12;
				if (map_people_x+12>=SIZEX)
					map_put_down=SIZEX;
				else
					map_put_down=map_people_x+12;
				
			}
		}
	}
	
}
 
