#include<stdio.h>

//typedef int F(void)

void say_hello(const char *str)
{
	printf("%s \n", str);
}

int main(char argc, char *argv[])
{
	void (*f)(const char *str) = say_hello;
	f("Guys");
	return 0;
}
