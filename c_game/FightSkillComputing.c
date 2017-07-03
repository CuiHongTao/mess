#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <windows.h>
#include <string.h>
int FightSkillComputing (struct state a[],struct monster m[],struct skill s[],int user,int number,int aim)
{
	void FightInforChange (char *fp[12],char infor[23]);
	void FightStart (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	void NumberChanges (char s[],int n);
	int CP (int x,int odex,int ydex);
	int Rands (int h,int f);
	char str[23]={"技能伤害"};
	int com;
//	if (Rands (0,100)<=CP (evd,ydex,odex))
//	{
//		FightInforChange (fp,"闪避成功");
//		FightStart (5,a,m,fp);
//		Sleep (500);
//		system ("cls");
//		return 0;
//	}
	
}
