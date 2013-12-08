#include<iostream>
#include<array>
#include<string>
#include<map>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<ios>
#include<algorithm>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::map;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::istream;

struct Student_info {
	std::string name;
	double midterm, final;	
	std::vector < double >homework;
};
bool compare(const Student_info &, const Student_info &);
std::istream & read(std::istream &, Student_info  &);
std::istream & read_hw(std::istream &, std::vector < double >&);
double grade(double, double, double);
double grade(double, double, const std::vector < double >&);
double grade(const Student_info &);
double median(std::vector < double >);
//void init_sort_rule( map<string, vector<string> >& sort_rule);
void sort_grade(map<string, vector<string> >& sort_rule, const string& name, const double& final_grade);

int main()
{
	vector < Student_info > students;
	Student_info record;
	string::size_type maxlen = 0;
	map<string, vector<string> > sort_rule;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	for (vector < Student_info >::size_type i = 0; i != students.size(); ++i) { 
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' '); 
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();

			cout << setprecision(3) << final_grade <<
			    setprecision(prec);
			sort_grade(sort_rule, students[i].name, final_grade);
		} catch(domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	for(map<string, vector<string> >::const_iterator it = sort_rule.begin(); it != sort_rule.end(); it++){
		for(vector<string>::const_iterator iter = it->second.begin(); iter < it->second.end(); iter++){
			cout << *iter << string(maxlen + 1 - (*iter).size(), ' ');
			cout << it->first << endl;
		}
	}

	return 0;
}

bool compare(const Student_info & x, const Student_info & y)
{
	return x.name < y.name;
}

istream & read(istream & is, Student_info & s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);

	return is;
}

istream & read_hw(istream & in, vector < double >&hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
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

//void init_sort_rule( map<string, vector<string> >& sort_rule)
//{
//	vector<string> sort_grade;
//	
//	sort_grade.push_back("90-100");
//	sort_grade.push_back("80-89.99");
//	sort_grade.push_back("70-79.99");
//	sort_grade.push_back("60-69.99");
//	sort_grade.push_back("<60");
//	
//	for (vector<string> :: size_type i = 0; i < sort_rule.size(); i++){
//		map<string,vector>
//	}
//}

void sort_grade(map<string, vector<string> >& sort_rule, const string& name, const double& final_grade)
{
	switch((int)(final_grade) / 10){
		case 9:
			sort_rule["90-100"].push_back(name);
			break;
		case 8:
			sort_rule["80-89.99"].push_back(name);
			break;
		case 7:
			sort_rule["70-79.99"].push_back(name);
			break;
		case 6:
			sort_rule["60-69.99"].push_back(name);
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0: 
			sort_rule["<60"].push_back(name);
			break;
		default:
			cout << "final_grade beyound range!"<<endl;
	}
}
