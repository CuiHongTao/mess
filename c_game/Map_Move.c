/*��ͼ�ƶ�����*/
 //ǽ -88 -128
 //�� -95 -30
 //�� -95 -14 
#include<stdio.h>
#include"Map_Head.c"
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
#include <D:\C����������Ϸ\MonsterStruct.c>
void Map_Move(char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[])
{	
	void Move_Up(char map[SIZEX][SIZEY],int x,int y);			//���ƶ��������� 
	void Move_Down(char map[SIZEX][SIZEY],int x,int y);			//���ƶ��������� 
	void Move_Left(char map[SIZEX][SIZEY],int x,int y);			//���ƶ��������� 
	void Move_Right(char map[SIZEX][SIZEY],int x,int y); 		//���ƶ��������� 
	void Map_Put(char map[SIZEX][SIZEY]);						//��ͼ����������� 
	void Map_People_Save(char map[SIZEX][SIZEY]);				//��ͼ���ﴢ�溯������ 
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
			case 'q':if(Menu(a,c,e,s,map)==0)return;Map_Save(map);break;//��ͼ���溯���������ﴢ��һ�𣬵����ô�������ʱһ�𴢴�
			
			case 'F':
			case 'f':Fight (a,m,s,c);break;
			
			case  72:												//���ϵķ���� 
			case 'W':
			case 'w':Move_Up(map,map_people_x,map_people_y);/*�����ƶ��ĺ���*/;break; 
			
			case  80:												//���µķ���� 
			case 'S':
			case 's':Move_Down(map,map_people_x,map_people_y)/*�����ƶ��ĺ���*/;break; 
			
			case  75:												//����ķ���� 
			case 'A':
			case 'a':Move_Left(map,map_people_x,map_people_y)/*�����ƶ��ĺ���*/;break; 
			
			case  77:												//���ҵķ���� 
			case 'D':
			case 'd':Move_Right(map,map_people_x,map_people_y)/*�����ƶ��ĺ���*/;break; 
			
			default:;
		} 
		

		Map_People_Search(map);		
		Map_Load(map);			//ÿ���ı��Ե�ͼ���ж�ȡ 
		map[map_people_x][map_people_y]=-95;			//�������긳ֵ 
		map[map_people_x][map_people_y+1]=-30;
		Map_Put(map);

	
	}

} 

//�����ƶ����жϺ���
void Move_Up(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//�����ַ�����switch�ж� 

	if((map[x-1][y]==-88)&&(map[x-1][y+1]==-128))		//ǽ 
		{command=1;} 
	else if((map[x-1][y]==-95)&&(map[x-1][y+1]==-14))	//�� 
		{command=2;}
	else if((map[x-1][y]==-88)&&(map[x-1][y+1]==-120))	//�� 
		{command=3;}  
		 
	switch(command)
	{
		case 1:	 
			map[x-1][y]=-88;						//ǽ��ԭ����λ�ò���
			map[x-1][y+1]=-128;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_up;map_come_from=1;break;
		
		case 3:	 
			map[x-1][y]=-88;						//����ԭ����λ�ò���
			map[x-1][y+1]=-120;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		default:	 
			map[x-1][y]=-95;						//�˵�λ�������ƶ�
			map[x-1][y+1]=-30; 
			map[x][y]=0;							//��λ����Ϊ0 
			map[x][y+1]=0;
	}

} 

//�����ƶ����жϺ���
void Move_Down(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//�����ַ�����switch�ж� 

	if((map[x+1][y]==-88)&&(map[x+1][y+1]==-128))		//ǽ 
		{command=1;} 
	else if((map[x+1][y]==-95)&&(map[x+1][y+1]==-14))	//�� 
		{command=2;}
	else if((map[x+1][y]==-88)&&(map[x+1][y+1]==-120))	//�� 
		{command=3;}
		 
	switch(command)
	{
		case 1:	 
			map[x+1][y]=-88;						//ǽ��ԭ����λ�ò���
			map[x+1][y+1]=-128;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_down;map_come_from=2;break;
		
		case 3:	 
			map[x+1][y]=-88;						//����ԭ����λ�ò���
			map[x+1][y+1]=-120;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		default:	 
			map[x+1][y]=-95;						//�˵�λ�������ƶ�
			map[x+1][y+1]=-30; 
			map[x][y]=0;							//��λ����Ϊ0 
			map[x][y+1]=0;
	}
} 

//�����ƶ����жϺ���
void Move_Left(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//�����ַ�����switch�ж� 

	if((map[x][y-2]==-88)&&(map[x][y-1]==-128))		//ǽ 
		{command=1;} 
	else if((map[x][y-2]==-95)&&(map[x][y-1]==-14))	//�� 
		{command=2;} 
	else if((map[x][y-2]==-88)&&(map[x][y-1]==-120))	//�� 
		{command=3;} 
		 	 
	switch(command)
	{
		case 1:	 
			map[x][y-2]=-88;						//ǽ��ԭ����λ�ò���
			map[x][y-1]=-128;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_left;map_come_from=3;break;
		
		case 3:	 
			map[x][y-2]=-88;						//����ԭ����λ�ò���
			map[x][y-1]=-120;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		default:	 
			map[x][y-2]=-95;						//�˵�λ�������ƶ�
			map[x][y-1]=-30; 
			map[x][y]=0;							//��λ����Ϊ0 
			map[x][y+1]=0;
	}
} 

//�����ƶ����жϺ���
void Move_Right(char map[SIZEX][SIZEY],int x,int y)
{	
	int command;										//�����ַ�����switch�ж� 

	if((map[x][y+2]==-88)&&(map[x][y+3]==-128))		//ǽ 
		{command=1;} 
	else if((map[x][y+2]==-95)&&(map[x][y+3]==-14))	//�� 
		{command=2;} 
	else if((map[x][y+2]==-88)&&(map[x][y+3]==-120))	//��
		{command=3;} 
		 
	switch(command)
	{
		case 1:	 
			map[x][y+2]=-88;						//ǽ��ԭ����λ�ò���
			map[x][y+3]=-128;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		case 2:Map_NextGoto(map,x,y);map_people_mark=map_right;map_come_from=4;break;
		
		case 3:	 
			map[x][y+2]=-88;						//����ԭ����λ�ò���
			map[x][y+3]=-120;
			map[x][y]=-95;							//��Ҳ��ԭ����λ�ã����ı�
			map[x][y+1]=-30;break;
		
		default:	 
			map[x][y+2]=-95;						//�˵�λ�������ƶ�
			map[x][y+3]=-30; 
			map[x][y]=0;							//��λ����Ϊ0 
			map[x][y+1]=0;
	}
} 

 //ǽ -88 -128
 //�� -95 -30
 //�� -95 -14
 //�� -88 -120 
