#include <stdlib.h>
#include <time.h>
int StochasticNumber()
{
	int i;
	srand((unsigned)time(NULL));
	i=rand ()%100;
	return i;
}
//用时间作种子返回0~100的随机数但是数值与时间成正比（操作快时会明显感觉到）
