#include<stdio.h>

#define _Bnd(X,bnd) (sizeof(X) + (bnd) & ~(bnd))

int main(void)
{
	int a;// = _Bnd(char, 3U);
	a = sizeof(char);
	a += (3U) & ~(3U);
//	int a =  sizeof(int);
//	int b = a + 4U;
//	int c = b & ~(4U);
//	//printf("%d,%d,%d\n",a,b,c);
	printf("%d\n", a);

	return 0;
}
