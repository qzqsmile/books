#include<stdio.h>

typedef struct {
	const char *name;
	int score;
} student_t;

static int cmp_student(const void *a, const void *b)
{
	if(((student_t *)a)->score > ((student_t *)b)->score)
		return 1;
	else if (((student_t *)a)->score == ((student_t *)b)-> score)
		return 0;
	else
		return -1;
}

int main(void)
{
	student_t list[4] = {{"Tom", 68},{"Jerry",72},
						{"Moby", 60},{"Kirby",89}};
	student_t *pmax = max(list, sizeof(list)/sizeof(student_t),
			sizeof(student_t), cmp_student);
	printf("%s gets the highest score %d\n",pmax->name, pmax->score);
	
	return 0;
}
