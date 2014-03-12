#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int *p;
	long int count = 0;

	while (1)
	{
		p = malloc(20);
		count++;
		if(p == NULL){
			printf("Out of memory\n");
			exit(1);
		}
	}
	return 0;
}
