#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <D:\C����������Ϸ\StateStruct.c>
#include <D:\C����������Ϸ\ConsumeStruct.c>
#include <D:\C����������Ϸ\SkillStruct.c>
#include <D:\C����������Ϸ\MonsterStruct.c>
#include <D:\C����������Ϸ\EquipStruct.c>
#include"Map_Head.c"
void Information (int t)//��Ϣ�������ȡ 
{
	FILE *fp;
	int Menu (struct state a[],struct consume c[],struct equip e[],struct skill s[]);//�ڲ��������������Ϣ 
	void Map_Main (char map[SIZEX][SIZEY],struct state a[],struct monster m[],struct equip e[],struct skill s[],struct consume c[]);//�ڲ����������ͼ��Ϣ 
	void Map_Load(char map[SIZEX][SIZEY]);
	void Map_People_Load(char map[SIZEX][SIZEY]);
	int q=1,i,j;
	struct state a[4];
	struct consume c[90];
	struct equip e[95];
	struct skill s[60];
	struct monster m[100];
	char map[SIZEX][SIZEY]={0};
	if (t==0)
	{
		for (i=0;i<4;i++)//���ĸ���ɫ״̬��ֵ
			{
				a[i].lv=10;
				a[i].exp=0;
				a[i].expmax=10;
				a[i].hp=100;
				a[i].hpmax=100;
				a[i].mp=30;
				a[i].mpmax=30;
				a[i].agile=10;
				a[i].mentality=10;
				a[i].physique=10;
				a[i].strength=10;
				for (j=0;j<20;j++)
					a[i].skill[j]=0;
				a[i].crit=0;
				a[i].dodge=0; 
			}
		printf ("��Ϊ���˹�ȡ�������������ֻ������ĸ���ڣ�\n");
		scanf ("%s",a[0].name);
		strcpy (a[1].name,"���1");
		strcpy (a[2].name,"���2");
		strcpy (a[3].name,"���3"); 
		for (i=0;i<90;i++)
			{
				c[i].lv=0;
				c[i].exp=0;
				c[i].hp=0;
				c[i].hpmax=0;
				c[i].mp=0;
				c[i].mpmax=0;
				c[i].agile=0;
				c[i].mentality=0;
				c[i].physique=0;
				c[i].strength=0;
				c[i].number=0;
				c[i].flag=0;
			}
		strcpy (c[0].name,"+1��");
		strcpy (c[0].infor,"+1��");
		c[0].number=1;
		c[0].strength=1;
		c[0].flag=1;
		strcpy (c[1].name,"+1��");
		strcpy (c[1].infor,"+1��");
		c[1].number=1;
		c[1].physique=1;
		c[1].flag=1;
		strcpy (c[2].name,"+1��");
		strcpy (c[2].infor,"+1��");
		c[2].number=1;
		c[2].agile=1;
		c[2].flag=1;
		strcpy (c[3].name,"+1��");
		strcpy (c[3].infor,"+1��");
		c[3].number=1;
		c[3].mentality=1;
		c[3].flag=1;
		strcpy (c[34].name,"+1ȫ");
		strcpy (c[34].infor,"+1ȫ");
		c[34].number=3;
		c[34].exp=1;
		c[34].flag=1;
		c[34].hp=2;
		c[34].hpmax=1;
		c[34].lv=1;
		c[34].mentality=1;
		c[34].mp=2;
		c[34].mpmax=1;
		c[34].physique=1;
		c[34].strength=1; 
		c[34].agile=1;
		for (i=0;i<95;i++)
			{
				e[i].hpmax=0;
				e[i].mpmax=0;
				e[i].agile=0;
				e[i].mentality=0;
				e[i].physique=0;
				e[i].strength=0;
				e[i].number=0;
				e[i].flag=0;
			}
		strcpy (e[0].name,"+1��");
		strcpy (e[0].infor,"+1����ͷ����");
		e[0].number=1;
		e[0].strength=1;
		e[0].flag=1;
		e[0].part=head;
		strcpy (e[1].name,"+1��");
		strcpy (e[1].infor,"+1�壨���壩");
		e[1].physique=1;
		e[1].number=1;
		e[1].flag=1;
		e[1].part=body;
		strcpy (e[2].name,"+1��");
		strcpy (e[2].infor,"+1�����Ȳ���");
		e[2].number=1;
		e[2].agile=1;
		e[2].flag=1;
		e[2].part=leg;
		strcpy (e[3].name,"+1��");
		strcpy (e[3].infor,"+1�ǣ��Ų���");
		e[3].number=1;
		e[3].mentality=1;
		e[3].flag=1;
		e[3].part=foot;
		strcpy (e[34].name,"+1ȫ");
		strcpy (e[34].infor,"+1ȫ��������");
		e[34].number=3;
		e[34].hpmax=1;
		e[34].mentality=1;
		e[34].mpmax=1;
		e[34].physique=1;
		e[34].strength=1;
		e[34].agile=1;
		e[34].flag=1;
		e[34].part=weapon;
		e[90].name[0]='\0';
		e[90].part=head;
		e[91].name[0]='\0';
		e[91].part=body;
		e[92].name[0]='\0';
		e[92].part=weapon;
		e[93].name[0]='\0';
		e[93].part=leg;
		e[94].name[0]='\0';
		e[94].part=foot;
		for (i=90;i<95;i++)
			e[i].number=5;
		for (i=0;i<4;i++)
			{
				a[i].head=90;
				a[i].body=91;
				a[i].weapon=92;
				a[i].leg=93;
				a[i].foot=94;
			}
		for (i=0;i<60;i++)
			{
				strcpy (s[i].name," ");
				s[i].basis=0;
				s[i].promote=0;
				s[i].type=monster;
				s[i].expend=0;
				strcpy (s[i].infor," ");
			}
		strcpy (s[1].name,"�˺�");
		s[1].basis=10;
		s[1].promote=0.1;
		s[1].type=monster;
		s[1].expend=1;
		strcpy (s[1].infor,"�˺����ܣ������˺� 10 �����ӳ� 0.1");
		strcpy (s[2].name,"�ظ�");
		s[2].basis=10;
		s[2].promote=0.1;
		s[2].type=own;
		s[2].expend=2;
		strcpy (s[2].infor,"�ظ����ܣ������ظ� 10 �����ӳ� 0.1");
		for (i=0;i<4;i++)
			for (j=0;j<20;j++)
				a[i].skill[j]=0;
		for (i=0;i<4;i++)
			{
				a[i].skill[0]=1;
				a[i].skill[1]=2;
			}
		
		map_people_x=3;
		map_people_y=6; 
		map_people_mark=1;
		Map_Load (map); 
		map[map_people_x][map_people_y]=-95;
		map[map_people_x][map_people_y+1]=-30;
		
	}
	if (t==1)
		{
			if ((fp=fopen ("abc","rb"))==NULL)
			{
				MessageBox (NULL,"�޵����ļ���"," ",MB_OK);
				exit (0);
			}
			for (i=0;i<4;i++)
				fread (&a[i],sizeof (struct state),1,fp);
			for (i=0;i<90;i++)
				fread (&c[i],sizeof (struct consume),1,fp);
			for (i=0;i<95;i++)
				fread (&e[i],sizeof (struct equip),1,fp);
			for (i=0;i<60;i++)
				fread (&s[i],sizeof (struct skill),1,fp);
			MessageBox (NULL,"�����ɹ���"," ",MB_OK);
			fclose (fp);
			Map_People_Load (map);
		}
	m[8].lv=1;
	m[8].agile=1;
	m[8].area=0;
	m[8].exp=1;
	m[8].flee=10;
	m[8].hp=10;
	m[8].hpmax=10;
	strcpy (m[8].infor,"���Թ���");
	m[8].mentality=1;
	m[8].mp=10;
	m[8].mpmax=10;
	m[8].physique=1;
	for (j=0;j<20;j++)
		m[8].skill[j]=0;
	m[8].skill[0]=1;
	m[8].skill[1]=2;
	m[8].strength=1;
	m[8].crit=0;
	m[8].dodge=0;
	strcpy (m[8].name,"����");
	system ("cls");Map_Main (map,a,m,e,s,c);
}
