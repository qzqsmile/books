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

bool Student_info::is_pass() const
{
	if ((midterm >= 60) && (final >= 60)){
		return (average_homework(homework) >= 60);
	}

	return 0;
}

double Student_info::average_homework(vector<double> hw) const
{
	double sum = 0;
	
	for (int i = 0; i < hw.size(); i++){
		sum += hw[i];
	}
	
	return (sum / (hw.size()));
}

bool compare(const Student_info& x, const Student_info& y)
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
