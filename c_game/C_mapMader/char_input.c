/*用户改变地图函数*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>//exit
#include"map_head.c"

void char_input(char map[SIZEX][SIZEY])
{
	char a[2];
	char command;
	int i,j;
	
	
	printf("1:汉字输入\t");
	printf("2:◆\t");
	printf("3:■\t");
	printf("4:删除\t");
	printf("5:人物\t");
	printf("6:门\n");
	p	:	command=getch();
	switch(command)
	
	{
		case '1':printf("请输入汉字：\n");scanf(" %s ",&a);break;
		case '2':strcpy(a,"◆");printf(" %s \n",a);break;
		case '3':a[0]=-88;a[1]=-128/*strcpy(a,"■")*/;printf(" %s \n",a);break;
		case '4':a[0]=0;a[1]=0;printf("要删除的位置\n");break;
		case '5':a[0]=-95;a[1]=-30;printf(" %s \n",a);break;
		case '6':a[0]=-95;a[1]=-14;printf(" %s \n",a);break;
		default:printf("命令不存在\n");goto p;
	}

	printf("i=\n");
	scanf("%d",&i);
	loop	:	printf("j=\n");
	
	
	scanf("%d",&j);
	if(j%2!=0)
		{	
			printf("j必须为双数\n");
			goto loop;
		}	
	
	map[i][j]=a[0];
	map[i][j+1]=a[1];
}
