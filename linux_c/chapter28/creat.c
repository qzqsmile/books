#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void)
{
	int fd;
	fd = creat("ex", 0777);
	return 0;
}
