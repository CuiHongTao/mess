/*��ͼ�ļ����溯��*/
#include<stdio.h>
#include<stdlib.h>
#include"Map_Head.c"

void Map_Save(char map[SIZEX][SIZEY])
{
	FILE *fp;
	int i,j;
	
	if ( (fp = fopen ("map.dat","r+") ) == NULL )				//д���ļ� 
	{
		printf ("�޷����ļ���\n");
		getch();
		exit(1);
	}
		
	for (i=0;i<SIZEX;i++)
	{
		for (j=0;j<SIZEY;j++,j++)
		{	if((map[i][j]==-95)&&(map[i][j+1]==-30))		//���� 
			{
				map[i][j]=0;
				map[i][j+1]=0;
				fprintf (fp,"%c",map[i][j]);				
				fprintf (fp,"%c",map[i][j+1]);
			}
			else
			{
				fprintf (fp,"%c",map[i][j]);				//��map��ֵд���ͼ�ļ�	
				fprintf (fp,"%c",map[i][j+1]);
			}	
			
		}
		fprintf (fp,"\n");
	}
		
	fclose(fp);
} 
