#ifndef PARA_CALLBACK_H
#define PARA_CALLBACK_H

typedef void (*callback_t)(void *);
void repeat_three_times(callback_t, void *);

#endif
