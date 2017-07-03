#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\StateStruct.c>
#include <D:\CÓïÑÔÎÄ×ÖÓÎÏ·\MonsterStruct.c>
#include <windows.h>
#include <string.h>
int FightAttackComputing (struct state a[],struct monster m[],int lv,int str,int crt, int odex,int def,int evd,int ydex,char *fp[12])
{
	void FightInforChange (char *fp[12],char infor[23]);
	void FightStart (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	void NumberChanges (char s[],int n);
	int CP (int x,int odex,int ydex);
	int Rands (int h,int f);
	char s[23]={"¸øÓèÉËº¦"}; 
	int com;
	if (Rands (0,100)<=CP (evd,ydex,odex))
		{
			FightInforChange (fp,"ÉÁ±Ü³É¹¦");
			FightStart (5,a,m,fp);
			Sleep (500);
			system ("cls");
			return 0;
		}
	com=(lv*20+str*50)*(1-((float)def-(float)str)/(float)def);
	if (Rands (0,100)<=CP (crt,odex,ydex))
		{
			FightInforChange (fp,"Ôì³É±©»÷");
			FightStart (5,a,m,fp);
			Sleep (500);
			system ("cls");
			NumberChanges (s,com*2);
			FightInforChange (fp,s);
			strcpy (s,"¸øÓèÉËº¦");
			FightStart (5,a,m,fp);
			Sleep (500);
			system ("cls");
			return com*2;
		}
	else
		{
			NumberChanges (s,com);
			FightInforChange (fp,s);
			strcpy (s,"¸øÓèÉËº¦"); 
			FightStart (5,a,m,fp);
			Sleep (500);
			system ("cls");
			return com;
		}
}
