#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<iostream>
#include<string>
#include<vector>
#include"Vec"

class Student_info{
    public:
	std::string name() const {return n;}
	bool valid() const{return !homework.size();}
	std::istream& read(std::istream&);
	double grade() const;
    private:
	std::string n;
	double midterm, final;
	Vec<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, Vec<double>&);

#endif
