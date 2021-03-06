#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<vector>
#include<iostream>
#include<string>

class Student_info{
	public:
		std::string name() const {return n;}
		bool valid() const{return !homework.empty();}
		std::istream& read(std::istream&);
		double grade() const;
		Student_info();
		Student_info(std::istream&);
	private:
		std::string n;
		double final_grade;
		double midterm, final;
		std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
