//long long a;
//int main(void)
//{
//	a=5;
//	return 0;
//}
#include<signal.h>

volatile sig_atomic_t a=0;

int main(void)
{
	while(!a);

	return 0;
}
