#include<iostream>
#include<string>

using std::string;

class Uncopyable{
	public:
		string s;
	protected:
		Uncopyable() {}
		~Uncopyable() {}
	private:
		Uncopyable(const Uncopyable&);
		Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale:private Uncopyable{

};

int main()
{
	Uncopyable s1;
	Uncopyable s2;
	HomeForSale s3;
	HomeForSale s4;
	
	s1 = s2;
	s3 = s4;

	return 0;
}
