#include<stdio.h>

int change(int a, int b)
{
	int c = (a & 0xffffff00) + (b & 0x000000ff);

	return c;
}

int main(void)
{
	int a = 0x89ABCDEF, b = 0x76543210;
	int c;
	c = change(a, b);

	printf("%X\n", c);

	return 0;
}
