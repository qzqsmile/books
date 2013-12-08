#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<vector>
#include<iostream>
#include<string>

using std::istream;
using std::string;
using std::vector;

class Student_info{
	public:
		string name() {return n;}
		bool valid() const{return !homework.empty();}
		istream& read(istream&);
		double grade() const;
	private:
		string n;
		double midterm, final;
		vector<double> homework;
};

bool compare(Student_info x,Student_info y);
std::istream& read_hw(istream&, vector<double>&);

#endif
