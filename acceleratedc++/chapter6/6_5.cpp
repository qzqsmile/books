#include<iostream>
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<string>

using std::domain_error;
using std::vector;
using std::string;
using std::cin;
using std::istream;

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector < double >homework;
};

double optimistic_median(const Student_info & s);
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector < double >&hw);
double grade(const Student_info & s);
double median(std::vector < double >vec);
istream &read(istream &is, Student_info & v);
istream & read_hw(istream& in, vector<double> & hw);

int main(void)
{
	vector<Student_info> students;
	Student_info x;
	
	while (read(cin,x)){
		students.push_back(x);
	}

	return 0;
}

double optimistic_median(const Student_info & s)
{
	vector < double >nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
			back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector < double >&hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info & s)
{
	return grade(s.midterm, s.final, s.homework);
}

double median(std::vector < double >vec)
{
	typedef vector < double >::size_type vec_sz;


	vec_sz size = vec.size();
	if (0 == size)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

istream &read(istream &is, Student_info & v)
{
    is >> v.name >> v.midterm >> v.final;
}

istream & read_hw(istream& in, vector<double> & hw)
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
