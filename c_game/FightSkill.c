#include <conio.h>
#include <stdio.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\MonsterStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
int FightSkill (int i,struct state a[],struct monster m[],struct skill s[],char *fightinfor[12])//ս�������ܺ��� 
{
	void FightSkillStart (int i,struct state a[],struct skill s[],struct monster m[],char *fightinfor[12]);
	char command;
	int command2;
	FightSkillStart (i,a,s,m,fightinfor);
	loop:
	command=getch ();
	switch (command)
		{
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
	printf ("%d",command2);
	if (command2>2)
		if (a[i].skill[command2-1]==0)
			{
				printf ("  ���ܲ�����\n");
				goto loop;
			}
	else
		return command2-1;
	loop2:
	command=getch ();
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
			case '9':command2=command2*10+command-48;break;
			default :;
		}
	if (command2>2)
		if (a[i].skill[command2-1]==0)
			{
				printf ("  ���ܲ�����\n");
				goto loop;
			}
	else
		return command2-1;
	return command2-1;
}
