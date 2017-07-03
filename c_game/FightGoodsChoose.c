#include <conio.h>
#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\StateStruct.c>
#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\MonsterStruct.c>
int FightGoodsChoose (int i,struct state a[],struct monster m[],char *fightinfor[12])
{
	void FightChoose (int i,int j,int k,struct state a[],struct monster m[],char *fightinfor[12]);
	char command;
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
