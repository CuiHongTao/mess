#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
void ConsumeUse (struct state a[],struct consume c[],int j)//�˵�����Ʒ������Ʒ��ʹ�� 
{
	int CharacterChoose (struct state a[]);
	void ConsumeInfor (struct consume c[],int j);
	int i;
	char flag;
	if (c[j].number<1)
		{
			printf ("��Ʒ������!\n");
			getch();
			return;
		}
	ConsumeInfor (c,j);
	i=CharacterChoose (a);
	printf ("�Ƿ�ʹ����Ʒ%5s��\n1.��\n����.��\n",c[j].name);
	flag=getch ();
	if (flag=='1')
		{
			a[i].lv+=c[j].lv;
			a[i].exp+=c[j].exp;
			a[i].hp+=c[j].hp;
			a[i].hpmax+=c[j].hpmax;
			if (a[i].hp>a[i].hpmax)
				{
					a[i].hp=a[i].hpmax;
					printf ("Ѫ���Ѵﵽ���ֵ\n");
					getch();
				}
			a[i].mp+=c[j].mp;
			a[i].mpmax+=c[j].mpmax;
			if (a[i].mp>a[i].mpmax)
				{
					a[i].mp=a[i].mpmax;
					printf ("�����Ѵﵽ���ֵ\n");
					getch();
				}
			a[i].strength+=c[j].strength;
			a[i].physique+=c[j].physique;
			a[i].agile+=c[j].agile;
			a[i].mentality+=c[j].mentality;
			c[j].number--;
		}
	else
		return;
}
