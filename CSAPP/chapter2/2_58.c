#include<stdio.h>

int is_big_endian()
{
	int x = 0x12345678;
	char *a = (char *)&x;
	if(*a == 0x12)
		return 1;
	else
		return 0;
}

int main(void)
{
	printf("%d\n",is_big_endian());
	
	return 0;
}
