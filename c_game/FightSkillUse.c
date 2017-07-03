#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <string.h>
#include <windows.h>
void FightSkillUse (struct state a[],struct monster m[],struct skill s[],char *fp[12],int user,int number,int aim)
{
	void FightInforChange (char *fp[12],char infor[23]);
	void FightStart (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	void NumberChanges (char s[],int n);
	char str[23];
	char num[23];
	if (s[a[user].skill[number]].type==1)
	{
		int hpup = (s[a[user].skill[number]].basis+(int)(a[user].mentality*s[a[user].skill[number]].promote));
		a[aim].hp += hpup;
		a[user].mp -= s[a[user].skill[number]].expend;
		if (a[aim].hp>a[aim].hpmax) a[aim].hp=a[aim].hpmax;
		strcpy (str,a[user].name);
		strcat (str,"使用技能:");
		strcat (str,s[a[user].skill[number]].name);
		FightInforChange (fp,str);
		FightStart (5,a,m,fp);
		Sleep (500);
		system ("cls");
		strcpy (str,a[aim].name);
		strcat (str,"回复");
		NumberChanges (str,hpup);
		FightInforChange (fp,str);
		FightStart (5,a,m,fp);
		Sleep (500);
		system ("cls");
	}
	else
	{
		m[aim].hp -= (s[a[user].skill[number]].basis+(int)(a[user].mentality*s[a[user].skill[number]].promote))*((m[aim].mentality-a[user].mentality)/m[aim].mentality);
		a[user].mp -= s[a[user].skill[number]].expend;
		
	}
}
