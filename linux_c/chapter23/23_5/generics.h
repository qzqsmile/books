#ifndef GENERICS_H
#define GENERICS_H

#include<stddef.h>

typedef int (*cmp_t) (const void *, const void *);
void *max (const void *base, size_t nmemb, size_t size, cmp_t cmp);

#endif
