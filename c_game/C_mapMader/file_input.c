/*�û��ı��ͼ����*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//exit
#include"map_head.c"

void file_input(char map[SIZEX][SIZEY])
{	
	void char_input(char map[SIZEX][SIZEY]);
	FILE *fp;
	int i,j;
	
	if ( (fp = fopen ("map.dat","r+") ) == NULL )				//д���ļ� 
		{
			printf ("�޷����ļ���\n");
			getch();
			exit(1);
		}
	
	char_input(map);
	
	for (i=0;i<SIZEX;i++)
		{
			for (j=0;j<SIZEY;j++,j++)
				{
					
					fprintf (fp,"%c",map[i][j]);				//��map��ֵд���ͼ�ļ�	
					fprintf (fp,"%c",map[i][j+1]);
				}
			fprintf (fp,"\n");
		}
		
	fclose(fp);
	
} 
