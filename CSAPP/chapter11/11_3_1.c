#include<netinet/in.h>
#include<stdio.h>

char *inet_ntoa(struct in_addr in);
int int_aton(const char *cp, struct in_addr *inp);

int main(void)
{
	unsigned long int a = 0x80000000;
	unsigned long int res = 0;

	res = htonl(a);
	printf("after htonl res = %ld\n", res);
	res = ntohl(res);
	printf("after ntohl res = %ld\n", res);
	printf("a = %ld\n", a);
	
	char *add;
	struct in_addr in, out;
	in.s_addr = 0xffffffff;
	add = inet_ntoa(in);
	printf("after inet_ntoa add = %s\n", add);
	inet_aton(add, &out);
	printf("after inet_aton add = %u\n",out.s_addr);
	printf("after inet_aton add = %u\n",in.s_addr);

	return 0;
}
