#include <conio.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
int FightSkillChoose (int i,int j,struct state a[],struct monster m[],struct skill s[],char *fightinfor[12])//战斗—技能目标选择函数 
{
	void FightChoose (int i,int j,int k,struct state a[],struct monster m[],char *fightinfor[12]);
	char command;
	if (s[a[i].skill[j]].type==0)
		{
			FightChoose (i,2,1,a,m,fightinfor);
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
					case '8':return command-49;
					default :goto loop;
				}
		}
	else
		{
			FightChoose (i,2,0,a,m,fightinfor);
			loop2:
			command=getch ();
			switch (command)
				{
					case 'a':return 0;
					case 'b':return 1;
					case 'c':return 2;
					case 'd':return 3;
					default :goto loop2;
				}
		}
}
