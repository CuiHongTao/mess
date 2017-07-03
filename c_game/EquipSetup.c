#include <D:\C语言文字游戏\StateStruct.c>
#include <D:\C语言文字游戏\EquipStruct.c>
void EquipSetup(struct state a[],struct equip e[],int i,int j)//菜单—装备—装备更换使人物数据改变 
{
	int condition;
	condition=e[i].part;
	switch (condition)
	{
		case 0: a[j].strength=a[j].strength-e[a[j].head].strength+e[i].strength;
				a[j].physique=a[j].physique-e[a[j].head].physique+e[i].physique;
				a[j].agile=a[j].agile-e[a[j].head].agile+e[i].agile;
				a[j].mentality=a[j].mentality-e[a[j].head].mentality+e[i].mentality;
				a[j].hpmax=a[j].hpmax-e[a[j].head].hpmax+e[i].hpmax;
				a[j].mpmax=a[j].mpmax-e[a[j].head].mpmax+e[i].mpmax;
				e[a[j].head].number++;
				a[j].head=i;break;
		case 1: a[j].strength=a[j].strength-e[a[j].body].strength+e[i].strength;
				a[j].physique=a[j].physique-e[a[j].body].physique+e[i].physique;
				a[j].agile=a[j].agile-e[a[j].body].agile+e[i].agile;
				a[j].mentality=a[j].mentality-e[a[j].body].mentality+e[i].mentality;
				a[j].hpmax=a[j].hpmax-e[a[j].body].hpmax+e[i].hpmax;
				a[j].mpmax=a[j].mpmax-e[a[j].body].mpmax+e[i].mpmax;
				e[a[j].body].number++;
				a[j].body=i;break;
		case 2: a[j].strength=a[j].strength-e[a[j].weapon].strength+e[i].strength;
				a[j].physique=a[j].physique-e[a[j].weapon].physique+e[i].physique;
				a[j].agile=a[j].agile-e[a[j].weapon].agile+e[i].agile;
				a[j].mentality=a[j].mentality-e[a[j].weapon].mentality+e[i].mentality;
				a[j].hpmax=a[j].hpmax-e[a[j].weapon].hpmax+e[i].hpmax;
				a[j].mpmax=a[j].mpmax-e[a[j].weapon].mpmax+e[i].mpmax;
				e[a[j].weapon].number++;
				a[j].weapon=i;break;
		case 3: a[j].strength=a[j].strength-e[a[j].leg].strength+e[i].strength;
				a[j].physique=a[j].physique-e[a[j].leg].physique+e[i].physique;
				a[j].agile=a[j].agile-e[a[j].leg].agile+e[i].agile;
				a[j].mentality=a[j].mentality-e[a[j].leg].mentality+e[i].mentality;
				a[j].hpmax=a[j].hpmax-e[a[j].leg].hpmax+e[i].hpmax;
				a[j].mpmax=a[j].mpmax-e[a[j].leg].mpmax+e[i].mpmax;
				e[a[j].leg].number++;
				a[j].leg=i;break;
		case 4: a[j].strength=a[j].strength-e[a[j].foot].strength+e[i].strength;
				a[j].physique=a[j].physique-e[a[j].foot].physique+e[i].physique;
				a[j].agile=a[j].agile-e[a[j].foot].agile+e[i].agile;
				a[j].mentality=a[j].mentality-e[a[j].foot].mentality+e[i].mentality;
				a[j].hpmax=a[j].hpmax-e[a[j].foot].hpmax+e[i].hpmax;
				a[j].mpmax=a[j].mpmax-e[a[j].foot].mpmax+e[i].mpmax;
				e[a[j].foot].number++;
				a[j].foot=i;break;
	}
	e[i].number--;
}
