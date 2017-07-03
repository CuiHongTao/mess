#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main ()//主函数 
{
	system("title 待取名");
	system("mode con cols=70 lines=27");
	srand((unsigned)time(NULL));
	void PrintStart ();
	void PrintEnd ();
	void Information (int t);
	char command;
	PrintStart ();
	for (command=getch();command!='0';command=getch())
		switch (command)
			{
				case '1':system ("cls");Information (0);system ("cls");PrintStart ();break;
				case '2':system ("cls");Information (1);system ("cls");PrintStart ();break;
				case '3':system ("cls");/*选项功能*/system ("cls");PrintStart ();break;
				case '4':system ("cls");/*附加可能*/system ("cls");PrintStart ();break;
				default:;break;
			}
	system ("cls");
	PrintEnd ();
	system ("pause");
	return 0;
}
