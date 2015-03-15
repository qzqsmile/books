#include"apue.h"

int main(int argc, char *argv[])
{
	int fd;

	fd = mkdir("hello", 0777);
	rmdir("hello");
	return 0;
}
