#ifndef RET_ALLOCATOR_H
#define RET_ALLOCATOR_H

typedef struct{
	int number;
	char *msg;
} unit_t;

unit_t *alloc_unit(void);
void free_unit(unit_t *);

#endif
