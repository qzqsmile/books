#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int Clentfd, port;
	char *host, buf[MAXLINE];
	rio_t rio;

	if(argc != 3){
		fprintf(stderr,"usage: %s <host> <port>\n", argv[0]);
	}
	host = argv[1];
	port = atoi(argv[2]);

	Clentfd = open_clientfd(host, prot);
	rio_read

	exit(0);
}
