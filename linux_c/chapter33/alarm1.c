#include<stdio.h>
#include<unistd.h>

int main(void)
{
	int counter = 0;
	alarm(4);
	sleep(1);
	counter = alarm(0);
	printf("alarm = %d\n", counter);
	while(1);
}
