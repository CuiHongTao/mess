#include <stdio.h>
#include <stdlib.h>
#include <D:\C����������Ϸ\EquipStruct.c>
void EquipInfor (struct equip e[],int j)//�˵���װ����װ����Ϣ����ʾ 
{
	if (e[j].flag==1)
		printf ("%s\n",e[j].infor);
	else
		printf ("δ���й���װ����\n");
}
