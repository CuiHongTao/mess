/*��map.dat�ļ��е����ݶ�ȡ��map������*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//exit
#include"map_head.c"

void file_Load(char map[SIZEX][SIZEY])
{
	FILE *fp;
	int i,j;

	if( (fp = fopen ("map.dat","r") ) == NULL )					//��map��ֵ��ȡ 
		{
			printf ("�޷����ļ���\n");
			getch();
			exit(1);
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

} 
