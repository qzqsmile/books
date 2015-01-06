class A{
	public:
		A();
};

class B{
	public:
		explicit B(int x = 0, bool b = true){ };
};

class C{
	public:
		explicit C(int x);
};

void dosomething(B bObject)
{
	;
}

int main(int argc, char **argv)
{
	B bObj1;
	dosomething(bObj1);
	B bObj2;

	dosomething(28);

	dosomething(B(28));

	return 0;
}
