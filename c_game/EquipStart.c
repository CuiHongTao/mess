#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
void EquipStart (struct state a[],struct equip e[],int j)//�˵���װ���������ʾ 
{
	int i,k=0;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("��```````````````````````````````````````````````````````````````��\n");
	printf ("|%5s    LV��%4d       |����%3d��   |ͷ����%5s                |\n",a[j].name,a[j].lv,a[j].strength,e[a[j].head].name);
	printf ("|EXP ��%5d/%5d       |�壺%3d��   |���壺%5s                |\n|",a[j].exp,a[j].expmax,a[j].physique,e[a[j].body].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ��");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("��%5d/%5d��     |����%3d��   |�Ȳ���%5s                |\n|",a[j].hp,a[j].hpmax,a[j].agile,e[a[j].leg].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("����");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("��%5d/%5d��     |�ǣ�%3d��   |�Ų���%5s                |\n",a[j].mp,a[j].mpmax,a[j].mentality,e[a[j].foot].name);
	printf ("|                        |            |������%5s                |\n",e[a[j].weapon].name); 
	printf ("|-----------------------------------------------------------------|\n");
	printf ("|");
	for (i=0;i<90;i++)
		if (e[i].flag==1)
			{
				if (e[i].number==0)
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
						printf ("%2d.",i+1);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
						printf ("%5s��%2d ",e[i].name,e[i].number);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					}
				else
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
						printf ("%2d.",i+1);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
						printf ("%5s��%2d ",e[i].name,e[i].number);
					}
					k++;
				if (k%5==0)
					printf ("|\n|");
			}
	while (k<90)
		{
			printf ("             ");
			k++;
			if(k%5==0)
				printf ("|\n|");
		}
	printf ("<<<<<<<<<<<<<<<<<<<<<<<<<<<<0. �� ��>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|\n");
}
