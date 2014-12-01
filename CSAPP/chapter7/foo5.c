#include<stdio.h>
void f(void);

int x = 151213;
int y = 151213;

int main(void)
{
	f();
	printf("x = 0x%x y = 0x%x \n", x, y);
	return 0;
}
