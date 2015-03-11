#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t counter_mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t counter_mutexB = PTHREAD_MUTEX_INITIALIZER;

void *doit(void *);
void *doanother(void *);

int main(int argc, char ** argv)
{
	pthread_t tidA, tidB;

	pthread_create(&tidA, NULL, doit, NULL);
	pthread_create(&tidB, NULL, doanother, NULL);
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);

	return 0;
}

void *doit(void *vptr)
{
	//lock A
	pthread_mutex_lock(&counter_mutexA);
	printf("hello world!\n");
	sleep(1);
	pthread_mutex_trylock(&counter_mutexB);
	pthread_mutex_unlock(&counter_mutexA);
}

void *doanother(void *vptr)
{
	//lock B
	pthread_mutex_lock(&counter_mutexB);
	printf("hello world!\n");
	sleep(1);
	pthread_mutex_trylock(&counter_mutexA);
	pthread_mutex_unlock(&counter_mutexB);

}
