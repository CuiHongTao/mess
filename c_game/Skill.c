#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
void Skill (struct state a[],struct skill s[])//�˵������ܺ��� 
{
	void SkillStart (struct state a[]);
	char Skill2 (struct state a[],struct skill s[],int i);
	char command;
	SkillStart (a);
	loop:
	command=getch();
	if (command=='0')
		return;
	loop2:
	switch (command)
		{
			case 'a':system ("cls");system ("color 07");command=Skill2 (a,s,0);break;
			case 'b':system ("cls");system ("color 07");command=Skill2 (a,s,1);break;
			case 'c':system ("cls");system ("color 07");command=Skill2 (a,s,2);break;
			case 'd':system ("cls");system ("color 07");command=Skill2 (a,s,3);break;
			default :goto loop;
		}
	if (command!='0')
		{
			system ("cls");
			SkillStart (a);
			goto loop2;
		}
}
	
