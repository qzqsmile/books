#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<iostream>
#include<string>
#include<vector>

class Student_info{
    public:
	std::string name() const {return n;}
	bool valid() const{return !homework.empty();}
	std::istream& read(istream&);
	double grade() const;
    private:
	std::string n;
	double midterm, final;
	vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(istream&, vector<double>&);

#endif
