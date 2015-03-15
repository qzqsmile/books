#include"apue.h"

int main(void)
{
	int fd;
	char buf[] = "Hello world!\n";
//	fd = dup(1);
	fd = open("/dev/fd/1", O_RDWR);
	write(fd,buf,13);
	return 0;
}
