#include<iostream>
#include<string>

using std::string;

template<class T>
class NamedObject{
	public:
		NamedObject(string& name, const T& value);
	private:
		std::string& nameValue;
		const T objectValue;
};

template<class T> NamedObject::NamedObject(string& name, const T& value)
{
	nameValue = name;
	objectValue = value;
}

int main(void)
{
	string newDog("Persephone");
	string oldDog("Satch");

	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);

//	p = s;
	return 0;
}
