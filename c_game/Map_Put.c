/*地图输出函数*/
#include<stdio.h>
#include"Map_Head.c"
#include<windows.h> 

void Map_Put(char map[SIZEX][SIZEY])
{	
	void setcolor(unsigned short ForeColor,unsigned short BackGroundColor);				//颜色函数声明 
	int i,j,color_command;
	for(i=map_put_up;i<map_put_down;i++)
	{
		for(j=map_put_left;j<map_put_right;j++,j++)
		{	
			if( (map[i][j]==-88) && (map[i][j+1]==-128) )//墙	-88 -128
			 	{color_command=1;}
			if( (map[i][j]==-95) && (map[i][j+1]==-14) )//门	-95 -14
			 	{color_command=2;}
			if( (map[i][j]==-95) && (map[i][j+1]==-30) )//人	-95 -30
			 	{color_command=3;}
			if( (map[i][j]==-88) && (map[i][j+1]==-120) )//海	-88 -120
			 	{color_command=4;}
			if( (map[i][j]==-95) && (map[i][j+1]==-7) )//草 -95 -7
			 	{color_command=5;}
			 	
			switch (color_command)
			{
				case 1:setcolor(6,0);break;			//墙 
				case 2:setcolor(12,0);break;		//门 
				case 3:setcolor(7,0);break;			//人 
				case 4:setcolor(9,0);break;		//海 
				case 5:setcolor(10,0);break;
				default:setcolor(5,0);				//其他 
			}
			
			if(map[i][j]==0)
				printf("  ");
			else
				printf("%c%c",map[i][j],map[i][j+1]);
					
		}
		printf("\n");
	}
} 

//颜色函数 ,用法：（字体颜色，背景颜色） 
void setcolor(unsigned short ForeColor,unsigned short BackGroundColor)
{	
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}
