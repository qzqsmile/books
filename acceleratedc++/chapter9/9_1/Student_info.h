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
		string name() const {return n;}
		bool valid() const{return !homework.empty();}
		istream& read(istream&);
		double grade() const;
		Student_info();
		Student_info(istream&);
	private:
		string n;
		double final_grade;
		double midterm, final;
		vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(istream&, vector<double>&);

#endif
