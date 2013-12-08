#include<iomanip>
#include<ios>
#include<iostream>
#include<string>

using std::cin;
using std::setprecision;
using std::cout;
using std::string;
using std::streamsize;
using std::endl;

int main(void)
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	cout << "Please input your final and midterm exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grades, "
		"followed by end-of-file ";

	int count = 0;
	double sum = 0;

	double x;

	while(cin >> x){
		++count;
		sum += x;
	}
	if(0 == count){
		cout << "Please input your homework grade again"<<endl;

		return 1;
	}

	streamsize prec = cout.precision();
	cout << "Your final grade is  " << setprecision(3) << 0.2*midterm + 0.4*sum/count << setprecision(prec)<<endl;


	return 0;
}
