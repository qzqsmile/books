#include"Student_info.h"
#include"grade.h"

istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	
	return in;
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool compare(Student_info x,Student_info y)
{
	return x.name() < y.name();
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
		hw.clear();
		
		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}
