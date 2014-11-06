#include<stdio.h>

void twiddle1(int *xp, int *yp)
{
	*xp += *yp;
	*xp += *yp;
}

void twiddle2(int *xp, int *yp)
{
	*xp += 2 * *yp;
}

int main(void)
{
	int x = 1000;
	twiddle1(&x, &x);
	printf("%d\n", x);
	x = 1000;
	twiddle2(&x, &x);
	printf("%d\n", x);
	return 0;
}
