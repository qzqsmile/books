#include<iostream>
#include<vector>
#include<iomanip>
#include<ios>

using std::vector;
using std::setprecision;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	vector<double> num;
	double x;
	double sum;
	double ave;

	cout << "Please input num" << endl;
	while(cin >> x)
	{
		num.push_back(x);
	}
	
	for (int i = 0; i < num.size(); i++)
	{
		sum += num[i];
	}
	
	ave = sum / num.size();

	cout << "The average num is " << ave << setprecision(3) <<endl;

	return 0;
}
