#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX 128

int main(int argc, char *argv[])
{
	int fd, i, j ;
	char *const ps_argv[] = {"ls","-al", NULL};
	char buf[MAX];
	char *saveptr1, saveptr2;
	char  *token, *subtoken;
	pid_t pid;

	while(1)
	{
		write(STDOUT_FILENO,"$", 1);
		read(STDIN_FILENO,buf,MAX);

		pid = fork();
		if(0 == pid)
		{
			for(i = 0; ;i++)
			{
				token = strtok_r(str1,'|', &saveptr1);
				if(token == NULL)
					break;
			}
			for(i = 0; ; i++)
			{
				token = strtok_r(str1,'<>',&saveptr2);
				if(token == NULL)
					break;
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
/*
   execute cmmand include pipe '|'
*/
void exe_pipe(char *buf)
{
	int i = 0;
	char *saveptr1;
	for(i = 0; ;i++)
	{
		token = strtok_r(str1, '|', &saveptr1);
		if(token == NULL)
		{
		}
		else
		{
		}
	}
}

/*
   execute command include '<>'
*/

/*
 */
