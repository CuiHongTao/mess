#include <conio.h>
#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\StateStruct.c>
#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\MonsterStruct.c>
int FightAttack (int i,struct state a[],struct monster m[],char *fightinfor[12])//Õ½¶·¡ª¹¥»÷º¯Êý 
{
	void FightChoose (int i,int j,int k,struct state a[],struct monster m[],char *fightinfor[12]);
	char command;
	FightChoose (i,1,1,a,m,fightinfor);
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
