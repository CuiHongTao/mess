/*把map.dat文件中的数据读取到map数组中*/
#include<stdio.h>
#include"map_head.c"

void map_put(char map[SIZEX][SIZEY])
{	
	int i,j;
	
	for(i=0;i<SIZEX;i++)		//输出数据 
		{
			for(j=0;j<SIZEY;j++,j++)
				{
					if(map[i][j]==0)
						printf("  ");
					else
						printf("%c%c",map[i][j],map[i][j+1]);
				}
			printf("\n");
		}
} 
