#include"Student_info.h"
#include"grade.h"
#include<iostream>

using std::istream;
using std::vector;
using std::cout;
using std::endl;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
// read name midterm and final
istream& read(istream& is, Student_info& s)
{	

	is >> s.name >>s.midterm >> s.final;
	read_hw(is, s.homework);

    return is;
}

//read homework
istream& read_hw(istream& in, vector<double>& hw)
{
	if(in){
		hw.clear();

		double x;
		while(in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}
