/*��ͼ����������ݴ���*/
#include<stdio.h>
#include<stdlib.h>
#include"Map_Head.c"

void Map_People_Save(char map[SIZEX][SIZEY]) 
{
	FILE *fp;
	
	if ( (fp = fopen ("map_people.dat","r+") ) == NULL )				//д���ļ� 
	{
		printf ("�޷����ļ���\n");
		getch();
		exit(1);
	}
	
	fprintf (fp,"%d",map_people_x);
	fprintf (fp,"\n");			
	fprintf (fp,"%d",map_people_y);
	fprintf (fp,"\n");
	fprintf (fp,"%d",map_people_mark);
	fprintf (fp,"\n");
	fprintf (fp,"%d",map_up);
	fprintf (fp,"\n");
	fprintf (fp,"%d",map_down);
	fprintf (fp,"\n");
	fprintf (fp,"%d",map_left);
	fprintf (fp,"\n");
	fprintf (fp,"%d",map_right);
	fprintf (fp,"\n");
	
	fclose(fp);
}
