#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
int CharacterChoose (struct state a[])//�˵�����Ʒ������Ʒ������ѡ�� 
{
	int i;
	char c;
	printf ("��˭ʹ�ã���1~4��\n");
	for (i=0;i<4;i++)
		printf ("%d.%5s\n",i+1,a[i].name);
	for (c=getch();(c<'1'||c>'4');c=getch())
		;
	return (int)c-49;
}
