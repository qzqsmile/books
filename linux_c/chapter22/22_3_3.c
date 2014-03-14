#include<stdio.h>

void foo(char buf3[20])
{
	printf("%u\n", sizeof(buf3));
}

int main(void)
{
	char *buf = "hello world!";
	char buf2[20] = "hello world";
	
	printf("%u\n%u\n%u\n", sizeof(buf), sizeof(buf2), sizeof("hello world"));;
	foo("hello world");

	return 0;
}
