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
	vector<double> homework;
	double midterm = 0;
	double final = 0;
	double final_grade = 0;

	is >> s.name;
	is >> midterm >> final;
	read_hw(is,homework);

// 	cout << homework[0] << homework[1] << endl;
	if (homework.size() == 0)
	{
		cout << "Wrong in Stu" << endl;
		while(1);
	}
	final_grade = grade(midterm,final,homework);
	s.final_grade = final_grade; 

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
