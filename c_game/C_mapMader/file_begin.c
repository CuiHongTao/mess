/*打开文件，当没有目标文件时创建文件*/
#include<stdio.h>
#include<stdlib.h>//exit
#include"map_head.c"

void file_begin(char map[SIZEX][SIZEY])
{	
	FILE *fp;
	int i,j;
	
	if ( (fp = fopen ("map.dat","r+") ) == NULL )				//写入文件 
		{
			printf ("无法找到目标文件！正在创建文件！\n");
			if ( (fp = fopen ("map.dat","w") ) == NULL )
				{
					printf("无法创建文件!\n");
					getch();
					exit(1);
				}
			printf("创建文件完成!\n"); 
		}
		
	fclose(fp);
}
