#include <conio.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
int FightInfor (int i,struct state a[],struct monster m[],char *fightinfor[12])//战斗—信息函数 
{
	void FightChoose (int i,int j,int k,struct state a[],struct monster m[],char *fightinfor[12]);
	char command;
	FightChoose (i,5,1,a,m,fightinfor);
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
			default:goto loop;
		}
}
