#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int fd;
	fd = open("New.txt", O_WRONLY | O_APPEND, 0666);
//	fd = open("New.txt", O_WRONLY | O_CREAT, 0666);
//	fd = open("New.txt", O_WRONLY | O_TRUNC, 0666);
//	fd = open("New.txt", O_WRONLY | O_CREATE | O_EXCL, 0666);
	close(fd);

	return 0;
}
