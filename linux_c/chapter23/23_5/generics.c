#include"generics.h"

void *max(const void *base, size_t nmemb, size_t size, cmp_t cmp)
{
	const char *_base = base;
	const char * temp = _base;
	size_t i;
	for(i = 1; i < nmemb; i++)
		if (cmp (temp, _base + size * i) < 0)
			temp = _base + size * i;

	return (void *)temp;
}
