#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void Switch (struct state a[],struct equip e[])//菜单—属性函数 
{
	void Attribute (struct state a[],struct equip e[],int i);
	int i,j;
	char command; 
	Attribute (a,e,i);
	for(i=0;command!='0';i++)
		{command=getch();
		switch (command)
			{
				case '1':system ("cls");j=0;Attribute (a,e,j);break;
				case '2':system ("cls");j=1;Attribute (a,e,j);break;
				case '3':system ("cls");j=2;Attribute (a,e,j);break;
				case '4':system ("cls");j=3;Attribute (a,e,j);break;
    	        case 'w':system ("cls");
					if(j==0)
						{system ("cls");j=3;Attribute (a,e,j);}
					else 
						{system ("cls");j--;Attribute (a,e,j);}
					break;
    	        case 's':system ("cls");
					if(j==3)
						{system ("cls");j=0;Attribute (a,e,j);}
					else 
						{system ("cls");j++;Attribute (a,e,j);}
					break;
				default :printf("〖 输入有误！请重新输入！〗\n");
			}
    	}
}
