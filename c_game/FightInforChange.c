void FightInforChange (char *fp[12],char infor[23])
{
	int i=0,j;
	for (i=0;i<11;i++)
		for (j=0;j<23;j++)
			fp[i][j]=fp[i+1][j];
	for (i=0;infor[i]!='\0';i++)
		fp[11][i]=infor[i];
	fp[11][i]='\0';
}
