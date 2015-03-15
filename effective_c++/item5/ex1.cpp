#include<iostream>
#include<string>

using namespace std;

class stu{
	public:
		int getsocre();
		int score;
		string name;
};

int stu::getsocre()
{
	return score;
}

int main(void)
{
	stu s;
	s.score = 1;
	s.name = "Q";
	cout << s.getsocre()<< endl;

	return 0;
}
