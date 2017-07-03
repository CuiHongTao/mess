#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include "Map_Head.c"
void File (struct state a[],struct consume c[],struct equip e[],struct skill s[],char map[SIZEX][SIZEY])//菜单—档案函数 
{
	void Map_Save (char map[SIZEX][SIZEY]);
	void Map_People_Save (char map[SIZEX][SIZEY]);
	void Map_People_Load (char map[SIZEX][SIZEY]);
	FILE *fp;
	int command,i;
	printf ("1.存入档案\n2.读取档案\n0.取    消\n");
	loop:
	command=getch();
	if (command=='1')
		{
			if ((fp=fopen ("abc","wb"))==NULL)
			{
				MessageBox (NULL,"无档案文件。"," ",MB_OK);
				exit (0);
			}
			for (i=0;i<4;i++)
				fwrite (&a[i],sizeof (struct state),1,fp);
			for (i=0;i<90;i++)
				fwrite (&c[i],sizeof (struct consume),1,fp);
			for (i=0;i<95;i++)
				fwrite (&e[i],sizeof (struct equip),1,fp);
			for (i=0;i<60;i++)
				fwrite (&s[i],sizeof (struct skill),1,fp);
			MessageBox (NULL,"存档成功！","提示",MB_OK);
			fclose (fp);
			Map_Save(map);
			Map_People_Save(map);
		}
	else if (command=='2')
		{
			if ((fp=fopen ("abc","rb"))==NULL)
			{
				MessageBox (NULL,"无档案文件。"," ",MB_OK);
				exit (0);
			}
			for (i=0;i<4;i++)
				fread (&a[i],sizeof (struct state),1,fp);
			for (i=0;i<90;i++)
				fread (&c[i],sizeof (struct consume),1,fp);
			for (i=0;i<95;i++)
				fread (&e[i],sizeof (struct equip),1,fp);
			for (i=0;i<60;i++)
				fread (&s[i],sizeof (struct skill),1,fp);
			MessageBox (NULL,"读档成功！","提示",MB_OK);
			fclose (fp);
			Map_People_Load (map);
		}
	else if (command=='0')
		return;
	else
		goto loop;
}
