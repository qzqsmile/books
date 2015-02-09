#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define MAXLINE 80

int main(void)
{
	int n;
	int fd[2];
	int count = 0;
	pid_t pid;
	char line[MAXLINE];
	
	if(pipe(fd) < 0){
		perror("pipe");
		exit(1);
	}
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	if(pid > 0){
		close(fd[0]);
		while(1){
			write(fd[1], "hello world\n", 12);
			count += 12;
			printf("The count is %d\n", count);
		}
		wait(NULL);
	}else{
		close(fd[1]);
//		close(fd[0]);
//		n = read(fd[0], line, MAXLINE);
//		write(STDOUT_FILENO, line, n);
		while(1);
	}
	return 0;
}
