#include <stdio.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
void FightEnd (int i,struct state a[],struct monster m[],struct skill s[],struct consume c[],char *fightinfor[12],int flog[])//战斗每回合结束界面的显示 
{
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("%5s ",a[0].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[0].hp,a[0].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[0]);
	printf ("%5s ",m[0].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[0].hp,m[0].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d",a[0].mp,a[0].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[1]);
	printf ("%5s ",m[1].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[1].hp,m[1].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[2]);
	printf ("%5s ",a[1].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[1].hp,a[1].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[3]);
	printf ("%5s ",m[2].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[2].hp,m[2].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d",a[1].mp,a[1].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[4]);
	printf ("%5s ",m[3].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[3].hp,m[3].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[5]);
	printf ("%5s ",a[2].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[2].hp,a[2].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[6]);
	printf ("%5s ",m[4].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[4].hp,m[4].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d",a[2].mp,a[2].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[7]);
	printf ("%5s ",m[5].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[5].hp,m[5].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[8]);
	printf ("%5s ",a[3].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",a[3].hp,a[3].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[9]);
	printf ("%5s ",m[6].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[6].hp,m[6].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("蓝量 %5d/%5d",a[3].mp,a[3].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[10]);
	printf ("%5s ",m[7].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("血量 %5d/%5d",m[7].hp,m[7].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[11]);
	printf ("=====================================================================\n");
	printf ("| 1.攻击 |这样决定可以吗？\n| 2.技能 |\n| 3.防御 |%s",a[i].name);
	switch (flog[0])
		{
			case 1:printf ("攻击%s",m[flog[1]].name);break;
			case 2:if (s[a[i].skill[flog[1]]].type==0)printf ("对%s",m[flog[2]].name);
			else printf ("对%s",a[flog[2]].name);printf ("使用技能%s",s[a[i].skill[flog[1]]].name);break;
			case 3:printf ("全力防御");break;
			case 4:printf ("对%s使用物品%s",a[flog[2]].name,c[flog[1]].name);break;
			case 5:printf ("刺探%s的信息",m[flog[1]].name);break;
			case 6:printf ("带领大家突破怪物封锁");break;
		}
	printf ("\n| 4.物品 |\n| 5.信息 |0.后悔了...\n| 6.逃跑 |其他.就这样决定！\n");
	printf ("=====================================================================\n");
}
