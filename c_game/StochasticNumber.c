#include <stdlib.h>
#include <time.h>
int StochasticNumber()
{
	int i;
	srand((unsigned)time(NULL));
	i=rand ()%100;
	return i;
}
//��ʱ�������ӷ���0~100�������������ֵ��ʱ������ȣ�������ʱ�����Ըо�����
