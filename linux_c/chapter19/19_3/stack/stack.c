char stack[512];
int top = -1;

extern char stack[512];
extern int top;

void push(char c)
{
	stack[++top] = c;
}
