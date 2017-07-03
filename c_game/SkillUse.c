#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\SkillStruct.c>
void SkillUse (struct state a[],struct skill s[],int i,int j)
{
	char command,command2;
	system ("cls");
	if (!a[i].skill[j])
		{
			printf ("技能不存在!\n");
			getch ();
		}
	else if (s[a[i].skill[j]].type==0)
		{
			printf ("攻击性技能，非战斗无法使用。\n");
			getch ();
		}
	else if (a[i].mp<s[a[i].skill[j]].expend)
		{
			printf ("MP不足，无法使用技能。\n");
			getch ();
		}
	else if (s[a[i].skill[j]].type)
		{
			printf ("请选择使用对象：\na.%s\nb.%s\nc.%s\nd.%s\n",a[0].name,a[1].name,a[2].name,a[3].name);
			loop:
			command=getch ();
			switch (command)
				{
					case 'a':
					case 'b':
					case 'c':
					case 'd':if (a[command-97].hp==a[command-97].hpmax) {printf ("该角色HP已满。\n");getch ();return;}
							 printf ("对%s使用技能%s？\n1.是\n其他.否\n",a[command-97].name,s[a[i].skill[j]].name);
							 command2=getch();if (command2==49)
							 	{
							 		a[command-97].hp+=(s[a[i].skill[j]].basis+(int)(a[i].mentality*s[a[i].skill[j]].promote));
							 		a[i].mp-=s[a[i].skill[j]].expend;
							 		if (a[command-97].hp>a[command-97].hpmax) a[command-97].hp=a[command-97].hpmax;
									break;
							 	}
							 else return;
					default :goto loop;
				}
		}
}
