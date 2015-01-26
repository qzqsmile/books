
int printf(const char *format, ...);

__attribute__((section("FOO"))) int global_init_var = 84;

__attribute__((section("BAR"))) void foo()
{
}

int global_uninit_var;

void func1(int i)
{
	printf("%d\n", i);
}

int main(void)
{
	static int static_var = 85;
	static int static_var2;
	int a = 1;
	int b;

	func1(static_var + static_var2 + a + b);

	return a;
}
