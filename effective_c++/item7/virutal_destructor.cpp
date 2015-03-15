#include<iostream>
#include<string>

using namespace std;

class SpecialString: public string{
	public:
		SpecialString();
};

int main(void)
{
	SpecialString *pss = new SpecialString("Impending Doom");
	string *ps;

	ps = pss;

	delete ps;

	return 0;
}
