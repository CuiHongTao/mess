#include <time.h>
#include <stdio.h>
int Rands (int h,int f)//��������� 
{
	int s;
	s=rand()%(f-h+1)+h;
	return s;
}
