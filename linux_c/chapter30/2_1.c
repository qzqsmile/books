#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	printf("PATH=%s\n", getenv("PATH"));
	setenv("PATH","Hell",1);
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
