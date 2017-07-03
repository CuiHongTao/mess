int Randomize(int n)//Ëæ»úÖµº¯Êı 
{
	int k,f,h;
	k=n*0.1;
	f=n*0.9;
	h=n*1.1;
	int s;
    rand()%h+f;
	s=rand()%(h-f+1)+f;
	return s;
}
