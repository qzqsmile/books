#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include"csapp.h"


void handler1(int sig)
{
	pid_t pid;

	if((pid = waitpid(-1, NULL, 0)) < 0)
		perror("waitpid error");
	printf("Handler reaped child %d\n", (int)pid);
	sleep(2);

	return;
}

int main()
{
	int i, n;
	char buf[MAXBUF];


	if(signal(SIGCHLD, handler1) == SIG_ERR)
		perror("signal error");

	for( i = 0; i < 3; i++){
		if(fork() == 0){
			printf("Hello from child %d\n",(int) getpid());
			sleep(1);
			exit(0);
		}
	}

	if((n == read(STDIN_FILENO, buf, sizeof(buf))) < 0)
		perror("read");

	printf("Parent processing input\n");
	while(1)
		;

	exit(0);
}
