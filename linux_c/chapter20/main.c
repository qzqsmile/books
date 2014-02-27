//#include"assert.h"
//#if 0
#include<stdio.h>
#include<stdlib.h>

#undef assert
#ifdef NDEBUG
	#define assert(test) ((void)0)
#else
 	extern void _Assert(char *);
	/*macros*/
	#define _STR(x) _VAL(x)
	#define _VAL(x) #x
	#define assert(test) ((test) ? (void)0 \
			: _Assert(__FILE__ ":" _STR(__LINE__) " " #test))
#endif

void _Assert(char *mesg)
{
	fputs(mesg, stderr);
	fputs(" -- assertion failed\n", stderr);
	abort();
}
//#endif 

int main(void)
{
	assert(2>3);

	return 0;
}
