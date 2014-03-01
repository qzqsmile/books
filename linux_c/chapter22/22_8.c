#include<stdio.h>

void hello(void)
{}

int main(void)
{
	void (*hello_ptr)(void);

	printf("hello:%p\n", hello);
	printf("&hello:%p\n", &hello);
	printf("*hello:%p\n", *hello);

	hello_ptr = hello;
	printf("hello_ptr = hello;\n");

	printf("hello_ptr:%p\n", hello_ptr);
	printf("&hello_ptr: %p\n", &hello_ptr);
	printf("*hello_ptr: %p\n", *hello_ptr);

	return 0;
}
