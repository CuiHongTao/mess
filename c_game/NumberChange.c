#include <string.h>
int Mult_10 (int n)
{  
  int sum = 10;
  int m;
  if(n==0) return 1;
  for(m=1;m<n;m++) sum*=10;
  return sum;
}
void NumberChanges (char s[],int n)
{
	int i,j=0,m;
	char c[7];
	if (n>1000000)
		{
			strcat (s,"999999");
			return;
		}
	for (m=6;m>=0;m--)
		{
			i=n/Mult_10 (m);
			n-=i*Mult_10 (m);
			if (i!=0)
				{
					c[j]=i+48;
					j++;
				}
			else if (i==0&&j!=0)
				{
					c[j]='0';
					j++;
				}
		}
	c[j]='\0';
	strcat (s,c);
}
