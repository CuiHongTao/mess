/*地图赋值函数(读取文件中的地图数组)*/
#include<stdio.h>
#include<stdlib.h>
#include"Map_Head.c"

void Map_Load(char map[SIZEX][SIZEY])
{
	FILE *fp;
	int i,j;
	//map_people_mark=1;
	
	switch(map_people_mark)
	{
		/*case 0:
			if((fp=fopen("map1.dat","r+"))==NULL)
			{
				printf("无法打开文件！\n");	
				getch();
				exit(1);
				
			};break;*/
		
		case 1:
			if((fp=fopen("map1.dat","r+"))==NULL)
			{
				printf("无法打开文件！\n");	
				getch();
				exit(1);
				
			};break;
			
		case 2:
			if((fp=fopen("map2.dat","r+"))==NULL)
			{
				printf("无法打开文件！\n");	
				getch();
				exit(1);
				
			};break;
			
		case 3:;break;
		default:;
	}
	
	while(!feof(fp))
	{
		for (i=0;i<SIZEX;i++)
		{
			for (j=0;j<SIZEY;j++,j++)
			{
				fscanf(fp,"%c",&map[i][j]);				
				fscanf(fp,"%c",&map[i][j+1]);
			}
			fscanf (fp,"\n");
		}
	}
	
	fclose(fp);
	
	
	
	if(map_come_from==1)	//上 
		{
			for(i=SIZEX-1;i>=0;i--)
			{
				for(j=SIZEY-1;j>=0;j--)
				{
					if((map[i][j-2]==-88)&&(map[i][j-1]==-128)&&(map[i][j]==-95)&&(map[i][j+1]==-14)&&(map[i][j+2]==-88)&&(map[i][j+3]==-128))
					{
						map_people_x=i-1;
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
							
						map_come_from=0;
						break;
					}
				}
			}
		}
		
		if(map_come_from==2)		//下 
		{
			for(i=0;i<SIZEX;i++)
			{
				for(j=0;j<SIZEY;j++)
				{
					if((map[i][j-2]==-88)&&(map[i][j-1]==-128)&&(map[i][j]==-95)&&(map[i][j+1]==-14)&&(map[i][j+2]==-88)&&(map[i][j+3]==-128))
					{
						map_people_x=i+1;
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
							
						map_come_from=0;
						break;
					}
				}
			}
		}
		
		
		if(map_come_from==3)		//左 
		{
			for(j=0;j<SIZEX;j++)
			{
				for(i=0;i<SIZEY;i++)
				{
					if((map[i-1][j]==-88)&&(map[i-1][j+1]==-128)&&(map[i][j]==-95)&&(map[i][j+1]==-14)&&(map[i+1][j]==-88)&&(map[i+1][j+1]==-128))
					{
						map_people_x=i;
						map_people_y=j+2;
						
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
							
						map_come_from=0;
						break;
					}
				}
			}
		}
		
		if(map_come_from==4)		//右 
		{
			for(j=SIZEX-1;j>=0;j--)
			{
				for(i=SIZEY;i>=0;i--)
				{
					if((map[i-1][j]==-88)&&(map[i-1][j+1]==-128)&&(map[i][j]==-95)&&(map[i][j+1]==-14)&&(map[i+1][j]==-88)&&(map[i+1][j+1]==-128))
					{
						map_people_x=i;
						map_people_y=j-2;
						
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
							
						map_come_from=0;
						break;
					}
				}
			}
		}
	
}
 //墙 -88 -128
 //人 -95 -30
 //门 -95 -14 
