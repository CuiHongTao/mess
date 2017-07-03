/*把map.dat文件中的数据读取到map数组中*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//exit
#include"map_head.c"

void file_Load(char map[SIZEX][SIZEY])
{
	FILE *fp;
	int i,j;

	if( (fp = fopen ("map.dat","r") ) == NULL )					//把map的值读取 
		{
			printf ("无法打开文件！\n");
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
