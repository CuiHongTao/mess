/*���ļ�����û��Ŀ���ļ�ʱ�����ļ�*/
#include<stdio.h>
#include<stdlib.h>//exit
#include"map_head.c"

void file_begin(char map[SIZEX][SIZEY])
{	
	FILE *fp;
	int i,j;
	
	if ( (fp = fopen ("map.dat","r+") ) == NULL )				//д���ļ� 
		{
			printf ("�޷��ҵ�Ŀ���ļ������ڴ����ļ���\n");
			if ( (fp = fopen ("map.dat","w") ) == NULL )
				{
					printf("�޷������ļ�!\n");
					getch();
					exit(1);
				}
			printf("�����ļ����!\n"); 
		}
		
	fclose(fp);
}
