#include"Student_info.h"
#include"Vec"
#include"grade.h"

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	
	return in;
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

std::istream& read_hw(std::istream& in, Vec<double>& hw)
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
