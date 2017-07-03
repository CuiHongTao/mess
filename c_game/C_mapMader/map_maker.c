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
	

	file_begin(map);			//打开文件，当没有目标文件时创建文件 
	
	file_Load(map);				//从文件map.dat中读取map的数据
	
	map_put(map);				//输出Map数组到屏幕 

//	file_input(map);			//用户改变数组 
	
//	map_put(map);				//输出Map数组到屏幕 
	
	while(1)
		{
			file_input(map);			//开始循环 
			map_put(map);				//开始循环
		}
	printf("system exit!\n");
	getch();
	return 0;	
}
