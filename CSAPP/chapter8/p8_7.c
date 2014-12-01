#include"csapp.h"

void handler(int sig)
{
	return;
}

unsigned int snooze(unsigned int secs){
	unsigned int rc = sleep(secs);
	printf("Slept for %u of %u secs\n", secs-rc, secs);
	return rc;
}

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "usage: %s <secs>\n", argv[0]);
		exit(0);
	}
	
	if(signal(SIGINT, handler) == SIG_ERR)
		perror("signal error\n");

	(void)snooze(atoi(argv[1]));
	exit(0);
}
