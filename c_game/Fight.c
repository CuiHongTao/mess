#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\MonsterStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
#include <D:\C语言文字游戏\ConsumeStruct.c>
void Fight (struct state a[],struct monster m[],struct skill s[],struct consume c[])//战斗函数
{
	void FightStart (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	int FightAttack (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	void FightEnd (int i,struct state a[],struct monster m[],struct skill s[],struct consume c[],char *fightinfor[12],int flog[]);
	int FightSkill (int i,struct state a[],struct monster m[],struct skill s[],char *fightinfor[12]);
	int FightSkillChoose (int i,int j,struct state a[],struct monster m[],struct skill s[],char *fightinfor[12]);
	int FightInfor (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	int FightGoods (struct consume c[]);
	int FightGoodsChoose (int i,struct state a[],struct monster m[],char *fightinfor[12]);
	int FightComputing (struct state a[],struct monster m[],struct skill s[],struct consume c[],int *flog[4],char *fp[12]);
	char command,i,j;
	char *fp[12];
	int flog[4][3]={0};
	int *f[4],con=0;
	char fightinfor[12][23]={" "};
	for (i=0;i<8;i++) m[i]=m[8];
	for (i=0;i<8;i++)
		{
			strcpy (fightinfor[i+4],"遇到");
			strcat (fightinfor[i+4],m[i].name);
		}
	for (i=0;i<4;i++)
		f[i]=flog[i];
	for (i=0;i<12;i++)
		fp[i]=fightinfor[i];
	while (con==0)
		{
			for (i=0;i<4;)
			{
				do
					{
						FightStart (i,a,m,fp);
						command=getch();
						if (command=='0')
							if (i==0);
							else
								{
									i--;
									goto loop;
								}
						system ("cls");
						switch (command)
							{
								case '1':flog[i][0]=1;flog[i][1]=FightAttack (i,a,m,fp);system ("cls");break;
								case '2':flog[i][0]=2;flog[i][1]=FightSkill (i,a,m,s,fp);while (a[i].mp<s[a[i].skill[flog[i][1]]].expend)
										 {printf ("mp不足，请重新选择。\n");getch();system ("cls");flog[i][0]=2;flog[i][1]=FightSkill (i,a,m,s,fp);}
										 system ("cls");flog[i][2]=FightSkillChoose (i,flog[i][1],a,m,s,fp);system ("cls");break;
								case '3':flog[i][0]=3;system ("cls");break;
								case '4':flog[i][0]=4;flog[i][1]=FightGoods (c);system ("cls");
										 flog[i][2]=FightGoodsChoose (i,a,m,fp);system ("cls");break;
								case '5':flog[i][0]=5;flog[i][1]=FightInfor(i,a,m,fp);system ("cls");break;
								case '6':flog[i][0]=6;system ("cls");break;
								default:flog[i][0]=0;
							}
					}while (flog[i][0]==0);
				FightEnd (i,a,m,s,c,fp,flog[i]);
				command=getch ();
				if (command=='0')
					;
				else
					i++;
				loop:
				system ("cls");
			}
			con=FightComputing (a,m,s,c,f,fp);
		}
	system ("cls");system ("color 07");
}
