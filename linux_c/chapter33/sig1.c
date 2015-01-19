#include<signal.h>

sig_atomic_t a=0;

int main(void)
{
	while(!a);
	
	return 0;
}
