#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
char Skill2 (struct state a[],struct skill s[],int i)//菜单—技能的下级函数 
{
	void SkillStart2 (struct state a[],struct skill s[],int i);
	void SkillUse (struct state a[],struct skill s[],int i,int j);
	char command;
	int command2;
	SkillStart2 (a,s,i);
	loop:
	command=getch();
	switch (command)
		{
			case '0':
			case 'a':
			case 'b':
			case 'c':
			case 'd':return command;break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':command2=command-48;break;
			default :goto loop;
		}
		if (command2>2)
			SkillUse (a,s,i,command2-1);
		else
			{
				printf ("%d",command2);
				loop2:
				command=getch();
				switch (command)
					{
						case '0':
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':
						case '8':
						case '9':command2=command2*10+command-49;break;
						default :SkillUse (a,s,i,command2-1);return i+97;
					}
				SkillUse (a,s,i,command2);
			}
	return i+97;
}
