#include<stdio.h>

#define STR(s) #s
#define CONCAT(a, b) a##b
#define showlist(...) printf(#__VA_ARGS__)
#define report(test, ...) ((test)?printf(#test):\printf(__VA_ARGS__))

#define sh(x) printf("n" #x "=%d, or %d\n", n##X, alt[x])
#define sub_z 26
sh(sub_z)

#define x 3
#define f(a) f(x * (a))
#undef x
#define x 2
#define g f
#define t(a) a

t(t(g)(0) + t) (1)

int main(void)
{
	int CONCAT(con, cat) = 1;
	printf(STR(hello  world!));
	printf("\n");
	if (1 == concat){
		printf("define success!");
	}
	showlist(The first, second, and third items);

	return 0;
}
