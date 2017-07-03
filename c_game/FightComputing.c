#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
#include <stdio.h>
#include <windows.h>
#include <string.h>
int FightComputing (struct state a[],struct monster m[],struct skill s[],struct consume c[],int *flog[4],char *fp[12])// 战斗—数据的计算
{
	int Rands (int h,int f);
	int FightAttackComputing (struct state a[],struct monster m[],int lv,int str,int crt, int odex,int def,int evd,int ydex,char *fp[12]);
	void AttributeMonster (struct monster m[],struct skill s[],int i);
	void FightInforChange (char *fp[12],char infor[23]);
	void FightStart (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	void FightSkillUse (struct state a[],struct monster m[],struct skill s[],char *fp[12],int user,int number,int aim);
	int temp[12][2],t[2];
	int i,j,te,def[4]={0};
	char str[23];
	for (i=0;i<12;i++)
		temp[i][0]=i;
	for (i=0;i<4;i++)
		temp[i][1]=a[i].agile;
	for (i=0;i<8;i++)
		temp[i+4][1]=m[i].agile;
	for (i=0;i<11;i++)
		for (j=0;j<11-i;j++)
			if (temp[j][1]<temp[j+1][1])
				{
					t[0]=temp[j][0];
					t[1]=temp[j][1];
					temp[j][0]=temp[j+1][0];
					temp[j][1]=temp[j+1][1];
					temp[j+1][0]=t[0];
					temp[j+1][1]=t[1];
				}
	for (i=0;i<12;i++)
  		{
			if (temp[i][0]>3)
				{
					if (m[temp[i][0]-4].hp==0)
						continue;
					te=Rands (0,3);
					while (a[te].hp==0)
						if (te==3) te=0;
						else te++;
					strcpy (str,m[temp[i][0]-4].name);
					strcat (str,"攻击");
					strcat (str,a[te].name);
					FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (500);system ("cls");
					a[te].hp-=FightAttackComputing (a,m,m[temp[i][0]-4].lv,m[temp[i][0]-4].strength,m[temp[i][0]-4].crit,m[temp[i][0]-4].agile,a[te].physique,a[te].dodge,a[te].agile,fp);
					if (a[te].hp<0) a[te].hp=0;
				}
			else
				{
					if (a[temp[i][0]].hp==0)
						continue;
					switch (flog[temp[i][0]][0])
						{
							case 1: while (m[flog[temp[i][0]][1]].hp==0) if (flog[temp[i][0]][1]==7) flog[temp[i][0]][1]=0; else flog[temp[i][0]][1]++;
									strcpy (str,a[temp[i][0]].name);strcat (str,"攻击");strcat (str,m[flog[temp[i][0]][1]].name);
									FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (500);system ("cls");
									m[flog[temp[i][0]][1]].hp-=FightAttackComputing (a,m,a[temp[i][0]].lv,a[temp[i][0]].strength,a[temp[i][0]].crit,a[temp[i][0]].agile,m[flog[temp[i][0]][1]].physique,m[flog[temp[i][0]][1]].dodge,m[flog[temp[i][0]][1]].agile,fp);
									if (m[flog[temp[i][0]][1]].hp<0) m[flog[temp[i][0]][1]].hp=0;break;
							case 2: if (s[flog[temp[i][0]][1]].type==1) {if (m[flog[temp[i][0]][2]].hp==0) {strcpy (str,"目标战斗不能");FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (1000);system ("cls"); break;}}
									else {if (a[flog[temp[i][0]][2]].hp==0) {strcpy (str,"目标战斗不能");FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (1000);system ("cls"); break;}}
									FightSkillUse (a,m,s,fp,temp[i][0],flog[temp[i][0]][1],flog[temp[i][0]][2]);break;
							case 3: strcpy (str,a[temp[i][0]].name);strcat (str,"全力防御");FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (500);system ("cls");
									def[temp[i][0]]=1;a[temp[i][0]].physique*=2;break;
							case 4:;
							case 5: strcpy (str,a[temp[i][0]].name);strcat (str,"刺探");strcat (str,m[flog[temp[i][0]][1]].name);FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (500);system ("cls");
									system ("cls");AttributeMonster (m,s,flog[temp[i][0]][1]);getch ();system ("cls");break;
							case 6: if (Rands (0,100)<(m[0].flee+m[1].flee+m[2].flee+m[3].flee+m[4].flee+m[5].flee+m[6].flee+m[7].flee))
										{strcpy (str,"队伍撤退了");FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (1000);system ("cls");return 3;}
									else {strcpy (str,"撤退失败");FightInforChange (fp,str);FightStart (5,a,m,fp);Sleep (500);system ("cls");}
						}
				}
			if ((m[0].hp+m[1].hp+m[2].hp+m[3].hp+m[4].hp+m[5].hp+m[6].hp+m[7].hp)==0) 
				{
					for (i=0;i<4;i++)
						if (def[i]==1)
							a[i].physique/=2;
					return 1;
				}
			if ((a[0].hp+a[1].hp+a[2].hp+a[3].hp)==0)
				{
					for (i=0;i<4;i++)
						if (def[i]==1)
							a[i].physique/=2;
					return 2;
				}
		}
	for (i=0;i<4;i++)
		if (def[i]==1)
			a[i].physique/=2;
	return 0;
}
