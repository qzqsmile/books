#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
	char buf[10];
	int n;
	int d_status;
	n = read(STDIN_FILENO, buf, 10);
	if(n < 0){
		perror("read STDIN_FILENO");
		exit(1);
	}
	close(STDOUT_FILENO);
//	n = open("out.c",O_WRONLY | O_CREAT | O_APPEND, 0x777);
	d_status = open("out", O_RDWR| O_CREAT, 0777);
	write(STDOUT_FILENO, buf, n);
	return 0;
}
