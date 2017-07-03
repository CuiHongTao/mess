/*读取文件中的人物在地图中的位置*/
#include<stdio.h>
#include<stdlib.h>
#include"Map_Head.c"

void Map_People_Load(char map[SIZEX][SIZEY])
{	
	void Map_Load(char map[SIZEX][SIZEY]);
	FILE *fp;
	
	if ( (fp = fopen ("map_people.dat","r+") ) == NULL )				//写入文件 
	{
		printf ("无法打开文件！\n");
		getch();
		exit(1);
	}
	
	while(!feof(fp))
	{
		fscanf (fp,"%d",&map_people_x);
		fscanf (fp,"\n");			
		fscanf (fp,"%d",&map_people_y);
		fscanf (fp,"\n");
		fscanf (fp,"%d",&map_people_mark);
		fscanf (fp,"\n");
		fscanf (fp,"%d",&map_up);
		fscanf (fp,"\n");
		fscanf (fp,"%d",&map_down);
		fscanf (fp,"\n");
		fscanf (fp,"%d",&map_left);
		fscanf (fp,"\n");
		fscanf (fp,"%d",&map_right);
		fscanf (fp,"\n");
	}	
		
	fclose(fp);
	
	Map_Load(map);													//对地图进行读取 
	
	map[map_people_x][map_people_y]=-95;
	map[map_people_x][map_people_y+1]=-30;
	
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
