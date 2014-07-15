#include<stdio.h>

int main(void)
{
	int a = 1;
	unsigned b = 2;
	
	printf("%d\n",(a-sizeof(int)));

	return 0;
}
