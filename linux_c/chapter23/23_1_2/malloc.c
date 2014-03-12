#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int number;
	char *msg;
} uint_it;

int main(void)
{
	uint_it *p = malloc(sizeof(uint_it));

	if (p == NULL){
		printf("out of memory\n");
		exit(1);
	}

	p->number = 3;
	p->msg = malloc(20);
	strcpy(p->msg, "Hello world!");
	printf("number: %d\nmsg:%s\n", p->number, p->msg);
	free(p->msg);
	free(p);
	p = NULL;

	return 0;
}
