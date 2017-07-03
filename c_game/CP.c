int CP (int x,int odex,int ydex)
{
	if ((100*(odex-ydex)/odex)>50)
		return x+50;
	return x+100*odex/(odex*2+ydex);
}
