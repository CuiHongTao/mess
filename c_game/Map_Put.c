/*��ͼ�������*/
#include<stdio.h>
#include"Map_Head.c"
#include<windows.h> 

void Map_Put(char map[SIZEX][SIZEY])
{	
	void setcolor(unsigned short ForeColor,unsigned short BackGroundColor);				//��ɫ�������� 
	int i,j,color_command;
	for(i=map_put_up;i<map_put_down;i++)
	{
		for(j=map_put_left;j<map_put_right;j++,j++)
		{	
			if( (map[i][j]==-88) && (map[i][j+1]==-128) )//ǽ	-88 -128
			 	{color_command=1;}
			if( (map[i][j]==-95) && (map[i][j+1]==-14) )//��	-95 -14
			 	{color_command=2;}
			if( (map[i][j]==-95) && (map[i][j+1]==-30) )//��	-95 -30
			 	{color_command=3;}
			if( (map[i][j]==-88) && (map[i][j+1]==-120) )//��	-88 -120
			 	{color_command=4;}
			if( (map[i][j]==-95) && (map[i][j+1]==-7) )//�� -95 -7
			 	{color_command=5;}
			 	
			switch (color_command)
			{
				case 1:setcolor(6,0);break;			//ǽ 
				case 2:setcolor(12,0);break;		//�� 
				case 3:setcolor(7,0);break;			//�� 
				case 4:setcolor(9,0);break;		//�� 
				case 5:setcolor(10,0);break;
				default:setcolor(5,0);				//���� 
			}
			
			if(map[i][j]==0)
				printf("  ");
			else
				printf("%c%c",map[i][j],map[i][j+1]);
					
		}
		printf("\n");
	}
} 

//��ɫ���� ,�÷�����������ɫ��������ɫ�� 
void setcolor(unsigned short ForeColor,unsigned short BackGroundColor)
{	
	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}
