#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
void SkillUse (struct state a[],struct skill s[],int i,int j)
{
	char command,command2;
	system ("cls");
	if (!a[i].skill[j])
		{
			printf ("���ܲ�����!\n");
			getch ();
		}
	else if (s[a[i].skill[j]].type==0)
		{
			printf ("�����Լ��ܣ���ս���޷�ʹ�á�\n");
			getch ();
		}
	else if (a[i].mp<s[a[i].skill[j]].expend)
		{
			printf ("MP���㣬�޷�ʹ�ü��ܡ�\n");
			getch ();
		}
	else if (s[a[i].skill[j]].type)
		{
			printf ("��ѡ��ʹ�ö���\na.%s\nb.%s\nc.%s\nd.%s\n",a[0].name,a[1].name,a[2].name,a[3].name);
			loop:
			command=getch ();
			switch (command)
				{
					case 'a':
					case 'b':
					case 'c':
					case 'd':if (a[command-97].hp==a[command-97].hpmax) {printf ("�ý�ɫHP������\n");getch ();return;}
							 printf ("��%sʹ�ü���%s��\n1.��\n����.��\n",a[command-97].name,s[a[i].skill[j]].name);
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
