#include <stdio.h>
#include <windows.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\MonsterStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
void FightEnd (int i,struct state a[],struct monster m[],struct skill s[],struct consume c[],char *fightinfor[12],int flog[])//ս��ÿ�غϽ����������ʾ 
{
	HANDLE handle = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("%5s ",a[0].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",a[0].hp,a[0].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[0]);
	printf ("%5s ",m[0].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[0].hp,m[0].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("���� %5d/%5d",a[0].mp,a[0].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[1]);
	printf ("%5s ",m[1].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[1].hp,m[1].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[2]);
	printf ("%5s ",a[1].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",a[1].hp,a[1].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[3]);
	printf ("%5s ",m[2].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[2].hp,m[2].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("���� %5d/%5d",a[1].mp,a[1].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[4]);
	printf ("%5s ",m[3].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[3].hp,m[3].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[5]);
	printf ("%5s ",a[2].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",a[2].hp,a[2].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[6]);
	printf ("%5s ",m[4].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[4].hp,m[4].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("���� %5d/%5d",a[2].mp,a[2].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[7]);
	printf ("%5s ",m[5].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[5].hp,m[5].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[8]);
	printf ("%5s ",a[3].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",a[3].hp,a[3].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[9]);
	printf ("%5s ",m[6].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[6].hp,m[6].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n      ");
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf ("���� %5d/%5d",a[3].mp,a[3].mpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("|%-23s|",fightinfor[10]);
	printf ("%5s ",m[7].name);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf ("Ѫ�� %5d/%5d",m[7].hp,m[7].hpmax);
	SetConsoleTextAttribute (handle,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf ("\n");
	printf ("----------------------|%-23s|----------------------\n",fightinfor[11]);
	printf ("=====================================================================\n");
	printf ("| 1.���� |��������������\n| 2.���� |\n| 3.���� |%s",a[i].name);
	switch (flog[0])
		{
			case 1:printf ("����%s",m[flog[1]].name);break;
			case 2:if (s[a[i].skill[flog[1]]].type==0)printf ("��%s",m[flog[2]].name);
			else printf ("��%s",a[flog[2]].name);printf ("ʹ�ü���%s",s[a[i].skill[flog[1]]].name);break;
			case 3:printf ("ȫ������");break;
			case 4:printf ("��%sʹ����Ʒ%s",a[flog[2]].name,c[flog[1]].name);break;
			case 5:printf ("��̽%s����Ϣ",m[flog[1]].name);break;
			case 6:printf ("������ͻ�ƹ������");break;
		}
	printf ("\n| 4.��Ʒ |\n| 5.��Ϣ |0.�����...\n| 6.���� |����.������������\n");
	printf ("=====================================================================\n");
}
