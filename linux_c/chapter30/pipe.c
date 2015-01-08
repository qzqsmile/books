#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#define MAXLINE 80

int main(void)
{
	int n;
	int fd[2];
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
		while(1)
		{
			write(fd[1], "hello world\n", 12);
			printf("writing\n");
		}
		wait(NULL);
	}else{
		close(fd[1]);
//		close(fd[0]);
//		n = read(fd[0], line, MAXLINE);
//		write(STDOUT_FILENO, line, n);
//		n = read(fd[0], line, MAXLINE);
	}
}
