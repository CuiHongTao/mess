#include<stdio.h>
#include<string.h>
#include<stdlib.h>//exit
#define SIZEX 5
#define SIZEY 10 

int main()
{
	FILE *fp;
	int i,j;
	char map[SIZEX][SIZEY];
	if((fp = fopen("map.txt","w")) == NULL)
		{
			printf("无法打开文件！\n");
			getch();
			exit(1);
		}
	for(i=0;i<SIZEX;i++)
		{
			for(j=0;j<SIZEY;j++,j++)
				{
					map[i][j]=-57; 
					map[i][j+1]=-67;
					fputc(map[i][j],fp);
					fputc(map[i][j+1],fp);
					//fprintf(fp,"%c",map[i][j]);	
					//fprintf(fp,"%c",map[i][j+1]);
				}
			fputc('\n',fp);
			//fprintf(fp,"\n");
		}

	for(i=0;i<SIZEX;i++)
		{
			for(j=0;j<SIZEY;j++,j++)
				{
					printf("%c",map[i][j]);	
					printf("%c",map[i][j+1]);
				}
			printf("\n");
		}
	fclose(fp);
	getch();
	return 0;	
}
