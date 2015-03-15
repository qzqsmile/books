#include"apue.h"

#define max 15

int main(void)
{
	char buf[max];
	size_t read_count;
	
	read_count = readlink("newlink", buf, max);
	buf[read_count] = '\0';
	printf("link name is = %s\n, read byte is = %d\n", buf, read_count);

	return 0;
}
