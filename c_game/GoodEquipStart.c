#include <stdio.h>
#include <windows.h>
#include <D:\C����������Ϸ\EquipStruct.c>
void GoodsEquipStart (struct equip e[])
{
	int i,j,k=0;
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("��```````````````````````````````````````````````````````````````��\n");
	printf ("||    ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("a.װ��");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("     |    b.����Ʒ   |    c.����     |    d.����Ʒ   ||\n");
	printf ("|-----------------------------------------------------------------|\n");
	printf ("|");
	for (i=0;i<90;i++)
		if (e[i].flag==1)
			{
				if (e[i].number==0)
					{
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
						printf ("%2d.%5s*%2d  ",i+1,e[i].name,e[i].number);
						SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					}
				else
					printf ("%2d.%5s*%2d  ",i+1,e[i].name,e[i].number);
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
	printf ("============================0. �� ��=============================|\n");
}
