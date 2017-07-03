#include <stdio.h>
#include <windows.h>
int main ()
{
	void equip ();
	void menustart ();
	menustart ();
	int command;
	for (scanf ("%d",&command);command!=0;scanf ("%d",&command))
		switch (command)
		{
			case 1:break;
			case 2:equip ();break;
			case 3:break;
			case 4:break;
			case 5:break;
			case 6:break;
			default:printf ("ÃüÁî²»´æÔÚ\n");
		}
	system ("cls");
}
