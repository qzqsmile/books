#include<stdio.h>

//const char **p;
//char *const *p;
//char **const p;

int main(void)
{
 	char *q = "hello world!";
	char *s = "Hi";
//	const char **p = &q;
	char *const *p = &q;
	
	*q = 'e';
//	*(q + 1) = '\0';
//	**p = 'n';
//	*((*p) + 1) = 'i';
//	*((*p) + 2) = '\0'; 

//	char **const p;
	
	printf("%s\n", *p);

	return 0;
}
