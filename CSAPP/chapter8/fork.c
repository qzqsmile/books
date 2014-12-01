#include<sys/types.h>
#include<unistd.h>

pid_t Fork(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
		perror("Fork error");
	return pid;
}
