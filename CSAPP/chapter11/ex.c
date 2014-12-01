#include<stdio.h>

int main(int argc, char **argv)
{
	fprintf(stderr, "error happen  %s\n", argv[1]);

	while(1);

	return 0;
}
