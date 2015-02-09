#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX 128

int main(int argc, char *argv[])
{
	int fd, i;
	pid_t pid;
	char *const ps_argv[] = {"ls","-al", NULL};
	char buf[MAX];

	while(1)
	{
		write(STDOUT_FILENO,"$", 1);
		read(STDIN_FILENO,buf,MAX);

		pid = fork();
		if(0 == pid)
		{
			for(i = 0; i != MAX; i++)
			{
				switch (buf[i])
				{
					case ' ':
						continue;
						break;
					default:
						break;

				}
			}
		}else if(pid > 0){
			wait(NULL);	
		}else{
			perror("fork failed");
			exit(1);
		}
//		execvp(argv[1],ps_argv);
//		perror("exec wrong!\n");
	}
	return 0;

}
