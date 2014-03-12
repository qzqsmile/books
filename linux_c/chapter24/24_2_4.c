#include<string.h>
#include<stdio.h>

char *strerror(int errnum);

int main(void)
{
	fprintf(stderr, "%s, line %d: %s\n",__FILE__, __LINE__, strerror(errno));
}
