#include<stdio.h>
#include<string.h>
//#include<stdlib.h>//exit
#include"map_head.c"

int main()
{	void file_begin(char map[SIZEX][SIZEY]);
	void file_Load(char map[SIZEX][SIZEY]);
	void map_put(char map[SIZEX][SIZEY]);
	void file_input(char map[SIZEX][SIZEY]);
	
	FILE *fp;
	int i,j;
	char map[SIZEX][SIZEY];
	
	for(i=0;i<SIZEX;i++)
		{
			for(j=0;j<SIZEY;j++)
				{
					map[i][j]=0;
				}
		}
	

	file_begin(map);			//���ļ�����û��Ŀ���ļ�ʱ�����ļ� 
	
	file_Load(map);				//���ļ�map.dat�ж�ȡmap������
	
	map_put(map);				//���Map���鵽��Ļ 

//	file_input(map);			//�û��ı����� 
	
//	map_put(map);				//���Map���鵽��Ļ 
	
	while(1)
		{
			file_input(map);			//��ʼѭ�� 
			map_put(map);				//��ʼѭ��
		}
	printf("system exit!\n");
	getch();
	return 0;	
}
