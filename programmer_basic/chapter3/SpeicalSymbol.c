#include<stdio.h>

//extern int  __executable_start[];
//extern int etext[], _etext[], __etext[];
//extern char edata[], _edata[];
//extern char end[], _end[];

int main()
{
	printf("Executable Start %X\n",__executable_start);
	printf("Text End %X %X %X\n", etext, _etext, __etext);
	printf("Data End %X %X\n", edata, _edata);
	printf("Executable End %X %X\n", end, _end);

	return 0;
}
