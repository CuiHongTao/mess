/*地图移动函数*/
 //墙 -88 -128
 //人 -95 -30
 //门 -95 -14 
#include<stdio.h>
#include"Map_Head.c"
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
void Map_Move(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[])
{	
	void Move_Up(char map[SIZEX][SIZEY],int x,int y);			//上移动函数声明 
	void Move_Down(char map[SIZEX][SIZEY],int x,int y);			//下移动函数声明 
	void Move_Left(char map[SIZEX][SIZEY],int x,int y);			//左移动函数声明 
	void Move_Right(char map[SIZEX][SIZEY],int x,int y); 		//右移动函数声明 
	void Map_Put(char map[SIZEX][SIZEY]);						//地图输出函数声明 
	void Map_People_Save(char map[SIZEX][SIZEY]);				//地图人物储存函数声明 
	void Map_Save(char map[SIZEX][SIZEY]); 						
	void Map_People_search(char map[SIZEX][SIZEY]);
	void Fight (struct state a[],struct monster m[],struct skill s[],struct consume c[]);
	int Menu (struct state a[],struct consume c[],struct equip e[],struct skill s[],char map[SIZEX][SIZEY]);
	int i,j;
	char command;
	map_come_from=0;
	while(1)
	{	
		command=getch();
		system("cls");
		switch(command)
		{
			case 'Q':
			case 'q':if(Menu(a,c,e,s,map)==0)return;Map_Save(map);break;//地图储存函数，跟人物储存一起，当调用储存命令时一起储存
			
			case 'F':
			case 'f':Fight (a,m,s,c);break;
			
			case  72:												//向上的方向键 
			case 'W':
			case 'w':Move_Up(map,map_people_x,map_people_y);/*向上移动的函数*/;break; 
			
			case  80:												//向下的方向键 
			case 'S':
			case 's':Move_Down(map,map_people_x,map_people_y)/*向下移动的函数*/;break; 
			
			case  75:												//向左的方向键 
			case 'A':
			case 'a':Move_Left(map,map_people_x,map_people_y)/*向左移动的函数*/;break; 
			
			case  77:												//向右的方向键 
			case 'D':
			case 'd':Move_Right(map,map_people_x,map_people_y)/*向右移动的函数*/;break; 
			
			default:;
		} 
		

		Map_People_Search(map);		
		Map_Load(map);			//每当改变后对地图进行读取 
		map[map_people_x][map_people_y]=-95;			//人物坐标赋值 
		map[map_people_x][map_people_y+1]=-30;
		Map_Put(map);

	
	}

} 

//向上移动的判断函数
void Move_Up(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//用于字符串的switch判断 

	if((map[x-1][y]==-88)&&(map[x-1][y+1]==-128))		//墙 
		{command=1;} 
	else if((map[x-1][y]==-95)&&(map[x-1][y+1]==-14))	//门 
		{command=2;}
	else if((map[x-1][y]==-88)&&(map[x-1][y+1]==-120))	//海 
		{command=3;}  
		 
	switch(command)
	{
		case 1:	 
			map[x-1][y]=-88;						//墙在原来的位置不变
			map[x-1][y+1]=-128;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_up;map_come_from=1;break;
		
		case 3:	 
			map[x-1][y]=-88;						//海在原来的位置不变
			map[x-1][y+1]=-120;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		default:	 
			map[x-1][y]=-95;						//人的位置向上移动
			map[x-1][y+1]=-30; 
			map[x][y]=0;							//该位置置为0 
			map[x][y+1]=0;
	}

} 

//向下移动的判断函数
void Move_Down(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//用于字符串的switch判断 

	if((map[x+1][y]==-88)&&(map[x+1][y+1]==-128))		//墙 
		{command=1;} 
	else if((map[x+1][y]==-95)&&(map[x+1][y+1]==-14))	//门 
		{command=2;}
	else if((map[x+1][y]==-88)&&(map[x+1][y+1]==-120))	//海 
		{command=3;}
		 
	switch(command)
	{
		case 1:	 
			map[x+1][y]=-88;						//墙在原来的位置不变
			map[x+1][y+1]=-128;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_down;map_come_from=2;break;
		
		case 3:	 
			map[x+1][y]=-88;						//海在原来的位置不变
			map[x+1][y+1]=-120;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		default:	 
			map[x+1][y]=-95;						//人的位置向上移动
			map[x+1][y+1]=-30; 
			map[x][y]=0;							//该位置置为0 
			map[x][y+1]=0;
	}
} 

//向左移动的判断函数
void Move_Left(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//用于字符串的switch判断 

	if((map[x][y-2]==-88)&&(map[x][y-1]==-128))		//墙 
		{command=1;} 
	else if((map[x][y-2]==-95)&&(map[x][y-1]==-14))	//门 
		{command=2;} 
	else if((map[x][y-2]==-88)&&(map[x][y-1]==-120))	//海 
		{command=3;} 
		 	 
	switch(command)
	{
		case 1:	 
			map[x][y-2]=-88;						//墙在原来的位置不变
			map[x][y-1]=-128;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_left;map_come_from=3;break;
		
		case 3:	 
			map[x][y-2]=-88;						//海在原来的位置不变
			map[x][y-1]=-120;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		default:	 
			map[x][y-2]=-95;						//人的位置向上移动
			map[x][y-1]=-30; 
			map[x][y]=0;							//该位置置为0 
			map[x][y+1]=0;
	}
} 

//向右移动的判断函数
void Move_Right(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//用于字符串的switch判断 

	if((map[x][y+2]==-88)&&(map[x][y+3]==-128))		//墙 
		{command=1;} 
	else if((map[x][y+2]==-95)&&(map[x][y+3]==-14))	//门 
		{command=2;} 
	else if((map[x][y+2]==-88)&&(map[x][y+3]==-120))	//海
		{command=3;} 
		 
	switch(command)
	{
		case 1:	 
			map[x][y+2]=-88;						//墙在原来的位置不变
			map[x][y+3]=-128;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_right;map_come_from=4;break;
		
		case 3:	 
			map[x][y+2]=-88;						//海在原来的位置不变
			map[x][y+3]=-120;
			map[x][y]=-95;							//人也在原来的位置，不改变
			map[x][y+1]=-30;break;
		
		default:	 
			map[x][y+2]=-95;						//人的位置向上移动
			map[x][y+3]=-30; 
			map[x][y]=0;							//该位置置为0 
			map[x][y+1]=0;
	}
} 

 //墙 -88 -128
 //人 -95 -30
 //门 -95 -14
 //海 -88 -120 
