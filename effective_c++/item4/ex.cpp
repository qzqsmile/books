#include<iostream>
#include<list>

class PhoneNumber {};
class ABEntry{
	public:
		ABEntry(const std::string& name, const std:: string& address,
				const std::list<PhoneNumber>& phones);
		ABEntry();
	private:
		std::string theName;
		std::string theAddress;
		std::list<PhoneNumber> thePhones;
		int numTimesConsulted;
};

//ABEntry::ABEntry(const std::string& name, const std::string& adderss,
//				const std::list<PhoneNumber>& phones)
//{
//	theName = name;
//	theAddress = adderss;
//	thePhones = phones;
//	numTimesConsulted = 0;
//}

//ABEntry::ABEntry(const std::string& name, const std::string& address,
//				const std::list<PhoneNumber>& phones)
//: theName(name), theAddress(address),
//	thePhones(phones),numTimesConsulted(0)
//{}

ABEntry::ABEntry()
	:theName(),
	 theAddress(),
	 thePhones(),
	 numTimesConsulted(0)
{}

int main(void)
{
	return 0;
}
